#include <iostream>
using namespace std;

struct Customer {
    int id;
    string name;
    string city;
};

class CustomerSystem {
    Customer arr[50];
    int n;

public:
    CustomerSystem() { n = 0; }

    // Add new customers
    void read() {
        int count;
        cout << "Enter number of customers to add: ";
        cin >> count;

        for(int i = 0; i < count; i++) {
            cout << "\nEnter Customer ID: ";
            cin >> arr[n].id;
            cout << "Enter Name: ";
            cin >> arr[n].name;
            cout << "Enter City: ";
            cin >> arr[n].city;
            n++;
        }
    }

    // Display customers
    void display() {
        if(n == 0) {
            cout << "\nNo customers available.\n";
            return;
        }
        cout << "\n--- Customer List ---\n";
        for(int i = 0; i < n; i++) {
            cout << "ID: " << arr[i].id
                 << "  Name: " << arr[i].name
                 << "  City: " << arr[i].city << endl;
        }
    }

    // Insert new customer at a given position
    void insert() {
        if(n == 50) {
            cout << "\nArray Full!\n";
            return;
        }

        int pos;
        cout << "Enter position to insert (0 to " << n << "): ";
        cin >> pos;

        if(pos < 0 || pos > n) {
            cout << "Invalid position!";
            return;
        }

        for(int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        cout << "Enter Customer ID: ";
        cin >> arr[pos].id;
        cout << "Enter Name: ";
        cin >> arr[pos].name;
        cout << "Enter City: ";
        cin >> arr[pos].city;

        n++;
        cout << "Inserted Successfully!\n";
    }

    // Update customer by ID
    void update() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;

        for(int i = 0; i < n; i++) {
            if(arr[i].id == id) {
                cout << "Enter new Name: ";
                cin >> arr[i].name;
                cout << "Enter new City: ";
                cin >> arr[i].city;
                cout << "Updated Successfully!\n";
                return;
            }
        }

        cout << "Customer not found!\n";
    }

    // Delete customer by ID
    void Delete() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        for(int i = 0; i < n; i++) {
            if(arr[i].id == id) {
                for(int j = i; j < n - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                n--;
                cout << "Deleted Successfully!\n";
                return;
            }
        }

        cout << "Customer not found!\n";
    }
};

int main() {
    CustomerSystem cs;
    int choice;

    do {
        cout << "\n--- Customer Management System ---\n";
        cout << "1. Read Customers\n";
        cout << "2. Display Customers\n";
        cout << "3. Insert Customer\n";
        cout << "4. Update Customer\n";
        cout << "5. Delete Customer\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cs.read(); break;
            case 2: cs.display(); break;
            case 3: cs.insert(); break;
            case 4: cs.update(); break;
            case 5: cs.Delete(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 6);

    return 0;
}

