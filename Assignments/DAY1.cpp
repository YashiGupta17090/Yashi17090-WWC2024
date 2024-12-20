// Develop a Warehouse Inventory Management System using C++ to simulate how industries manage and track their inventory.
//The program should enable users to add new items to the inventory, update stock levels, track inventory movement, and generate reports.
//Each item in the inventory should be represented as an object with attributes like a unique item ID, name, category, quantity, and reorder level.
//The system should include functionality to alert the user when stock levels fall below the reorder threshold. 
//A menu-driven interface should allow users to perform operations such as viewing inventory, searching for items by name or category, 
//and exporting inventory data to a file for record-keeping. This assignment is designed to mirror real-world inventory management systems 
//used in industries like retail, manufacturing, and logistics, providing hands-on experience with object-oriented design, file handling, and user interaction in C++.
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Inventory Item class
class InventoryItem {
public:
    int itemID;
    string name;
    string category;
    int quantity;
    int reorderLevel;

    // Constructor to initialize an item
    InventoryItem(int id, string n, string c, int q, int r) 
        : itemID(id), name(n), category(c), quantity(q), reorderLevel(r) {}

    // Method to display item details
    void display() const {
        cout << "Item ID: " << itemID << endl;
        cout << "Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Reorder Level: " << reorderLevel << endl;
        cout << "------------------------------------\n";
    }

    // Method to check if stock is below reorder level
    bool needsRestocking() const {
        return quantity < reorderLevel;
    }

    // Method to update the quantity of the item
    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }
};

// Warehouse class to manage inventory
class Warehouse {
private:
    vector<InventoryItem> inventory;
    int nextID = 1;  // Unique ID for new items

public:
    // Method to add a new item
    void addItem(string name, string category, int quantity, int reorderLevel) {
        InventoryItem newItem(nextID++, name, category, quantity, reorderLevel);
        inventory.push_back(newItem);
        cout << "Item added successfully!\n";
    }

    // Method to view all items
    void viewInventory() {
        if (inventory.empty()) {
            cout << "Inventory is empty.\n";
        } else {
            for (const auto& item : inventory) {
                item.display();
                if (item.needsRestocking()) {
                    cout << "ALERT: Item needs restocking!\n";
                }
            }
        }
    }

    // Method to search for an item by name
    void searchByName(string name) {
        bool found = false;
        for (const auto& item : inventory) {
            if (item.name == name) {
                item.display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item not found.\n";
        }
    }

    // Method to search for an item by category
    void searchByCategory(string category) {
        bool found = false;
        for (const auto& item : inventory) {
            if (item.category == category) {
                item.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No items found in this category.\n";
        }
    }

    // Method to update stock level of an item
    void updateStock(int itemID, int newQuantity) {
        bool found = false;
        for (auto& item : inventory) {
            if (item.itemID == itemID) {
                item.updateQuantity(newQuantity);
                cout << "Stock updated successfully!\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item not found.\n";
        }
    }

    // Method to export inventory data to a file
    void exportInventoryToFile() {
        ofstream file("inventory_data.txt");
        if (file.is_open()) {
            for (const auto& item : inventory) {
                file << "Item ID: " << item.itemID << endl;
                file << "Name: " << item.name << endl;
                file << "Category: " << item.category << endl;
                file << "Quantity: " << item.quantity << endl;
                file << "Reorder Level: " << item.reorderLevel << endl;
                file << "------------------------------------\n";
            }
            cout << "Inventory data exported successfully to inventory_data.txt.\n";
        } else {
            cout << "Error opening file for writing.\n";
        }
    }
};

// Main program to drive the menu interface
int main() {
    Warehouse warehouse;
    int choice;

    do {
        cout << "\nWarehouse Inventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Item by Name\n";
        cout << "4. Search Item by Category\n";
        cout << "5. Update Stock\n";
        cout << "6. Export Inventory to File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name, category;
        int quantity, reorderLevel, itemID;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin.ignore(); // to clear the input buffer
                getline(cin, name);
                cout << "Enter item category: ";
                getline(cin, category);
                cout << "Enter item quantity: ";
                cin >> quantity;
                cout << "Enter reorder level: ";
                cin >> reorderLevel;
                warehouse.addItem(name, category, quantity, reorderLevel);
                break;
            case 2:
                warehouse.viewInventory();
                break;
            case 3:
                cout << "Enter item name to search: ";
                cin.ignore();
                getline(cin, name);
                warehouse.searchByName(name);
                break;
            case 4:
                cout << "Enter category to search: ";
                cin.ignore();
                getline(cin, category);
                warehouse.searchByCategory(category);
                break;
            case 5:
                cout << "Enter item ID to update stock: ";
                cin >> itemID;
                cout << "Enter new stock quantity: ";
                cin >> quantity;
                warehouse.updateStock(itemID, quantity);
                break;
            case 6:
                warehouse.exportInventoryToFile();
                break;
            case 7:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}


