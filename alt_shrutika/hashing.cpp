// Hashing with Linear Probing
#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 6;

struct ColdDrink {
    int key;            // unique key
    string name;        // cold drink flavor
    bool occupied;      // flag to mark if slot is occupied
};

// Function to initialize hash table
void initializeTable(ColdDrink table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1;
        table[i].name = "";
        table[i].occupied = false;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert using linear probing (without replacement)
void insertDrink(ColdDrink table[], int key, string name) {
    int index = hashFunction(key);
    int start = index;

    // Linear probing
    while (table[index].occupied) {
        index = (index + 1) % TABLE_SIZE;

        if (index == start) {
            cout << "Hash table is full! Cannot insert: " << name << endl;
            return;
        }
    }

    table[index].key = key;
    table[index].name = name;
    table[index].occupied = true;

    cout << "Inserted \"" << name << "\" at index " << index << endl;
}

// Display hash table
void displayTable(ColdDrink table[]) {
    cout << "\n--- Cold Drink Hash Table ---\n";
    cout << "Index\tKey\tFlavor\n";
    cout << "----------------------------\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].occupied)
            cout << i << "\t" << table[i].key << "\t" << table[i].name << endl;
        else
            cout << i << "\t-\tEmpty" << endl;
    }
}

// Search a cold drink
void searchDrink(ColdDrink table[], int key) {
    int index = hashFunction(key);
    int start = index;

    while (table[index].occupied) {
        if (table[index].key == key) {
            cout << "Found flavor \"" << table[index].name 
                 << "\" at index " << index << endl;
            return;
        }

        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            break;
    }

    cout << "Flavor with key " << key << " not found!\n";
}

int main() {
    ColdDrink table[TABLE_SIZE];
    initializeTable(table);

    int choice, key;
    string name;

    do {
        cout << "\n===== Cold Drink Corner Menu =====";
        cout << "\n1. Insert Cold Drink";
        cout << "\n2. Display Table";
        cout << "\n3. Search Cold Drink";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Cold Drink Key (number): ";
            cin >> key;
            cout << "Enter Cold Drink Flavor Name: ";
            cin >> name;
            insertDrink(table, key, name);
            break;

        case 2:
            displayTable(table);
            break;

        case 3:
            cout << "Enter Key to Search: ";
            cin >> key;
            searchDrink(table, key);
            break;

        case 4:
            cout << "Exiting... Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

