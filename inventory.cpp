#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100;

int productIDs[MAX_PRODUCTS];
string productNames[MAX_PRODUCTS];
int quantities[MAX_PRODUCTS];
double prices[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Inventory is full." << endl;
        return;
    }

    cout << endl << "Add a new product" << endl;

    // Safe input for product ID
    cout << "ID: ";
    while (!(cin >> productIDs[productCount])) {
        cin.clear();
        cin.ignore(10000, '\n'); // Clear the input buffer
        cout << "Invalid input. Enter a valid product ID: ";
    }
    cin.ignore(); // Ignore the newline character after the integer input

    // Safe input for product name (get entire line)
    cout << "Name: ";
    getline(cin, productNames[productCount]);

    // Safe input for quantity
    cout << "Quantity: ";
    while (!(cin >> quantities[productCount])) {
        cin.clear();
        cin.ignore(10000, '\n'); // Clear the input buffer
        cout << "Invalid input. Enter a valid quantity: ";
    }

    // Safe input for price
    cout << "Price: ";
    while (!(cin >> prices[productCount])) {
        cin.clear();
        cin.ignore(10000, '\n'); // Clear the input buffer
        cout << "Invalid input. Enter a valid price: ";
    }

    productCount++;
    cout << "Product added." << endl;
}

void viewProducts() {
    if (productCount == 0) {
        cout << "No products yet." << endl;
        return;
    }

    cout << endl << "All Products:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << productIDs[i]
             << ", Name: " << productNames[i]
             << ", Quantity: " << quantities[i]
             << ", Price: $" << prices[i] << endl;
    }
}

void searchProductByID() {
    int id;
    cout << endl << "Search by ID: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Clear the input buffer
        cout << "Invalid input. Enter a valid ID: ";
    }

    for (int i = 0; i < productCount; i++) {
        if (productIDs[i] == id) {
            cout << "Found - Name: " << productNames[i]
                 << ", Quantity: " << quantities[i]
                 << ", Price: $" << prices[i] << endl;
            return;
        }
    }

    cout << "Product not found." << endl;
}

void updateProduct() {
    int id;
    cout << endl << "Update a product by ID: ";
    while (!(cin >> id)) {
        cin.clear();
        cin.ignore(10000, '\n'); // Clear the input buffer
        cout << "Invalid input. Enter a valid ID: ";
    }

    for (int i = 0; i < productCount; i++) {
        if (productIDs[i] == id) {
            // Safe input for new quantity
            cout << "New quantity: ";
            while (!(cin >> quantities[i])) {
                cin.clear();
                cin.ignore(10000, '\n'); // Clear the input buffer
                cout << "Invalid input. Enter a valid quantity: ";
            }

            // Safe input for new price
            cout << "New price: ";
            while (!(cin >> prices[i])) {
                cin.clear();
                cin.ignore(10000, '\n'); // Clear the input buffer
                cout << "Invalid input. Enter a valid price: ";
            }

            cout << "Updated." << endl;
            return;
        }
    }

    cout << "Product not found." << endl;
}

int main() {
    int choice;

    while (true) {
        cout << endl << "Inventory Menu" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Products" << endl;
        cout << "3. Search Product by ID" << endl;
        cout << "4. Update Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";

        // Safe input for menu choice
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n'); // Clear the input buffer
            cout << "Invalid input. Try again: ";
        }

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: searchProductByID(); break;
            case 4: updateProduct(); break;
            case 5: return 0;
            default: cout << "Invalid option." << endl;
        }
    }

    return 0;
}