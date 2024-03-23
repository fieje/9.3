#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Price {
    string productName; 
    string storeName;  
    double productPrice; 
};

void inputPrices(Price* prices, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "Enter data for product #" << i + 1 << ":" << endl;
        cout << "Product name: ";
        getline(cin >> ws, prices[i].productName); 
        cout << "Store name: ";
        getline(cin >> ws, prices[i].storeName); 
        cout << "Product price (UAH): ";
        cin >> prices[i].productPrice; 
    }
}

void sortByStoreName(Price* prices, const int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (prices[j].storeName > prices[j + 1].storeName) {
                Price temp = prices[j];
                prices[j] = prices[j + 1];
                prices[j + 1] = temp;
            }
        }
    }
}

void printPriceInfo(const Price* prices, const int N, const string& productName) {
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (prices[i].productName == productName) {
            found = true;
            cout << "Information about product \"" << productName << "\":" << endl;
            cout << "Store: " << prices[i].storeName << endl; 
            cout << "Price: " << fixed << setprecision(2) << prices[i].productPrice << " UAH" << endl; 
        }
    }
    if (!found) {
        cout << "Product with name \"" << productName << "\" not found." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of products: ";
    cin >> N;

    Price* prices = new Price[N];

    cin.ignore(); 

    inputPrices(prices, N);

    sortByStoreName(prices, N);

    cout << "List of products sorted by store name:" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << prices[i].productName 
            << " - " << prices[i].storeName << " - " 
            << fixed << setprecision(2) 
            << prices[i].productPrice << " UAH" << endl;
    }

    string productName;
    cout << "Enter the product name to get information: ";
    getline(cin >> ws, productName);

    printPriceInfo(prices, N, productName);

    delete[] prices;

    return 0;
}
