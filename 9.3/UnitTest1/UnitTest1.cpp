#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../9.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
	TEST_CLASS(PriceManagementTests)
	{
	public:

		TEST_METHOD(InputPricesTest)
		{
			const int N = 2; 
			Price prices[N];
			std::istringstream input("Product1\nStore1\n10.5\nProduct2\nStore2\n20.5\n");
			std::streambuf* oldcin = std::cin.rdbuf(input.rdbuf());
			inputPrices(prices, N);
			std::cin.rdbuf(oldcin);

			Assert::AreEqual(std::string("Product1"), prices[0].productName);
			Assert::AreEqual(std::string("Store1"), prices[0].storeName);
			Assert::AreEqual(10.5, prices[0].productPrice);

			Assert::AreEqual(std::string("Product2"), prices[1].productName);
			Assert::AreEqual(std::string("Store2"), prices[1].storeName);
			Assert::AreEqual(20.5, prices[1].productPrice);
		}

		TEST_METHOD(SortByStoreNameTest)
		{
			const int N = 3;
			Price prices[N] = { {"Prod1", "StoreC", 30.0},
								{"Prod2", "StoreA", 20.0},
								{"Prod3", "StoreB", 10.0} };
			sortByStoreName(prices, N);

			Assert::AreEqual(std::string("StoreA"), prices[0].storeName);
			Assert::AreEqual(std::string("StoreB"), prices[1].storeName);
			Assert::AreEqual(std::string("StoreC"), prices[2].storeName);
		}

		TEST_METHOD(PrintPriceInfoTest)
		{
			const int N = 2;
			Price prices[N] = { {"Prod1", "Store1", 10.0},
								{"Prod2", "Store2", 20.0} };
			std::ostringstream output;
			std::streambuf* oldcout = std::cout.rdbuf(output.rdbuf());
			printPriceInfo(prices, N, "Prod2");
			std::cout.rdbuf(oldcout);

			Assert::IsTrue(output.str().find("Information about product \"Prod2\":") != std::string::npos);
			Assert::IsTrue(output.str().find("Store: Store2") != std::string::npos);
			Assert::IsTrue(output.str().find("Price: 20.00 UAH") != std::string::npos);
		}
	};
}
