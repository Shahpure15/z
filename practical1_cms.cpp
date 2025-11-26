#include <iostream>
#include <string>
using namespace std;

// Class to represent a Customer object
class Customer {
public:
    int custID;
    string name;
    string phone;
    string email;
    float balance;

    // Default Constructor
    Customer() {
        custID = 0;
        name = "";
        phone = "";
        email = "";
        balance = 0.0;
    }

    // Parameterized Constructor
    Customer(int id, string n, string p, string e, float b) {
        custID = id;
        name = n;
        phone = p;
        email = e;
        balance = b;
    }
};

// Class to manage Customer database with array
class CustomerManagement {
private:
    Customer customers[100];  // Fixed size array (max 100 customers)
    int customerCount;        // Number of customers currently stored

public:
    // Constructor
    CustomerManagement() {
        customerCount = 0;
    }

    // Check if Customer ID already exists
    bool isCustomerIDExist(int id) {
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].custID == id) {
                return true;
            }
        }
        return false;
    }

    // Insert new customer
    void insertCustomer() {
        if (customerCount >= 100) {
            cout << "Database is full. Cannot add more customers.\n";
            return;
        }

        int id;
        string n, p, e;
        float b;

        cout << "Enter Customer ID: ";
        cin >> id;

        if (isCustomerIDExist(id)) {
            cout << "Customer ID already exists! Please use a unique ID.\n";
            return;
        }

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, n);
        cout << "Enter Phone Number: ";
        getline(cin, p);
        cout << "Enter Email: ";
        getline(cin, e);
        cout << "Enter Account Balance: ";
        cin >> b;

        customers[customerCount] = Customer(id, n, p, e, b);
        customerCount++;

        cout << "Customer added successfully!\n";
    }

    // Display all customers
    void displayCustomers() {
        if (customerCount == 0) {
            cout << "No customers available to display.\n";
            return;
        }

        cout << "\n--- Customer List ---\n";
        for (int i = 0; i < customerCount; i++) {
            cout << "Customer ID: " << customers[i].custID << "\n";
            cout << "Name: " << customers[i].name << "\n";
            cout << "Phone: " << customers[i].phone << "\n";
            cout << "Email: " << customers[i].email << "\n";
            cout << "Balance: $" << customers[i].balance << "\n";
        }
    }

    // Find customer by ID
    void findCustomerByID() {
        int id;
        cout << "Enter Customer ID to search: ";
        cin >> id;

        for (int i = 0; i < customerCount; i++) {
            if (customers[i].custID == id) {
                cout << "\n--- Customer Details ---\n";
                cout << "Customer ID: " << customers[i].custID << "\n";
                cout << "Name: " << customers[i].name << "\n";
                cout << "Phone: " << customers[i].phone << "\n";
                cout << "Email: " << customers[i].email << "\n";
                cout << "Balance: $" << customers[i].balance << "\n";
                return;
            }
        }

        cout << "Customer with ID " << id << " not found.\n";
    }

    // Update customer details
    void updateCustomer() {
        int id;
        cout << "Enter Customer ID to update: ";
        cin >> id;

        for (int i = 0; i < customerCount; i++) {
            if (customers[i].custID == id) {
                string newName, newPhone, newEmail;
                float newBalance;
                cin.ignore();

                cout << "Enter new Name: ";
                getline(cin, newName);
                cout << "Enter new Phone: ";
                getline(cin, newPhone);
                cout << "Enter new Email: ";
                getline(cin, newEmail);
                cout << "Enter new Balance: ";
                cin >> newBalance;

                customers[i].name = newName;
                customers[i].phone = newPhone;
                customers[i].email = newEmail;
                customers[i].balance = newBalance;

                cout << "Customer updated successfully!\n";
                return;
            }
        }

        cout << "Customer with ID " << id << " not found.\n";
    }

    // Delete customer by ID
    void deleteCustomer() {
        int id;
        cout << "Enter Customer ID to delete: ";
        cin >> id;

        for (int i = 0; i < customerCount; i++) {
            if (customers[i].custID == id) {
                // Shift all customers after deleted one to the left
                for (int j = i; j < customerCount - 1; j++) {
                    customers[j] = customers[j + 1];
                }

                customerCount--;
                cout << "Customer deleted successfully!\n";
                return;
            }
        }

        cout << "Customer with ID " << id << " not found.\n";
    }

    // Menu
    void showMenu() {
        int choice;

        do {
            cout << "\n--- Customer Management System ---\n";
            cout << "1. Insert Customer\n";
            cout << "2. Display All Customers\n";
            cout << "3. Find Customer by ID\n";
            cout << "4. Update Customer\n";
            cout << "5. Delete Customer\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertCustomer();
                    break;
                case 2:
                    displayCustomers();
                    break;
                case 3:
                    findCustomerByID();
                    break;
                case 4:
                    updateCustomer();
                    break;
                case 5:
                    deleteCustomer();
                    break;
                case 6:
                    cout << "Exiting the system...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    CustomerManagement cm;
    cm.showMenu();
    return 0;
}
