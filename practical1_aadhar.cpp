#include <iostream>
#include <string>
using namespace std;

// Class to represent an Aadhar Card object
class AadharCard {
public:
    long long aadharNo;
    string name;
    string address;
    string dob;
    string gender;

    // Default Constructor
    AadharCard() {
        aadharNo = 0;
        name = "";
        address = "";
        dob = "";
        gender = "";
    }

    // Parameterized Constructor
    AadharCard(long long ano, string n, string addr, string d, string g) {
        aadharNo = ano;
        name = n;
        address = addr;
        dob = d;
        gender = g;
    }
};

// Class to manage Aadhar Card database with array
class AadharManagement {
private:
    AadharCard cards[100];  // Fixed size array (max 100 cards)
    int cardCount;          // Number of cards currently stored

public:
    // Constructor
    AadharManagement() {
        cardCount = 0;
    }

    // Check if Aadhar number already exists
    bool isAadharExist(long long ano) {
        for (int i = 0; i < cardCount; i++) {
            if (cards[i].aadharNo == ano) {
                return true;
            }
        }
        return false;
    }

    // Insert new Aadhar card
    void insertAadhar() {
        if (cardCount >= 100) {
            cout << "Database is full. Cannot add more Aadhar cards.\n";
            return;
        }

        long long ano;
        string n, addr, d, g;

        cout << "Enter 12-digit Aadhar Number: ";
        cin >> ano;

        // Validate 12 digits
        if (ano < 100000000000LL || ano > 999999999999LL) {
            cout << "Invalid Aadhar Number! Must be 12 digits.\n";
            return;
        }

        if (isAadharExist(ano)) {
            cout << "Aadhar Number already exists!\n";
            return;
        }

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, n);
        cout << "Enter Address: ";
        getline(cin, addr);
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin, d);
        cout << "Enter Gender (M/F/O): ";
        getline(cin, g);

        cards[cardCount] = AadharCard(ano, n, addr, d, g);
        cardCount++;

        cout << "Aadhar Card added successfully!\n";
    }

    // Display all Aadhar cards
    void displayAadharCards() {
        if (cardCount == 0) {
            cout << "No Aadhar cards available to display.\n";
            return;
        }

        cout << "\n--- Aadhar Card Records ---\n";
        for (int i = 0; i < cardCount; i++) {
            cout << "Aadhar Number: " << cards[i].aadharNo << "\n";
            cout << "Name: " << cards[i].name << "\n";
            cout << "Address: " << cards[i].address << "\n";
            cout << "Date of Birth: " << cards[i].dob << "\n";
            cout << "Gender: " << cards[i].gender << "\n";
        }
    }

    // Find Aadhar card by number
    void findAadharByNumber() {
        long long ano;
        cout << "Enter Aadhar Number to search: ";
        cin >> ano;

        for (int i = 0; i < cardCount; i++) {
            if (cards[i].aadharNo == ano) {
                cout << "\n--- Aadhar Card Details ---\n";
                cout << "Aadhar Number: " << cards[i].aadharNo << "\n";
                cout << "Name: " << cards[i].name << "\n";
                cout << "Address: " << cards[i].address << "\n";
                cout << "Date of Birth: " << cards[i].dob << "\n";
                cout << "Gender: " << cards[i].gender << "\n";
                return;
            }
        }

        cout << "Aadhar Card with number " << ano << " not found.\n";
    }

    // Update Aadhar card details
    void updateAadhar() {
        long long ano;
        cout << "Enter Aadhar Number to update: ";
        cin >> ano;

        for (int i = 0; i < cardCount; i++) {
            if (cards[i].aadharNo == ano) {
                string newName, newAddr, newDob, newGender;
                cin.ignore();

                cout << "Enter new Name: ";
                getline(cin, newName);
                cout << "Enter new Address: ";
                getline(cin, newAddr);
                cout << "Enter new Date of Birth: ";
                getline(cin, newDob);
                cout << "Enter new Gender: ";
                getline(cin, newGender);

                cards[i].name = newName;
                cards[i].address = newAddr;
                cards[i].dob = newDob;
                cards[i].gender = newGender;

                cout << "Aadhar Card updated successfully!\n";
                return;
            }
        }

        cout << "Aadhar Card with number " << ano << " not found.\n";
    }

    // Delete Aadhar card by number
    void deleteAadhar() {
        long long ano;
        cout << "Enter Aadhar Number to delete: ";
        cin >> ano;

        for (int i = 0; i < cardCount; i++) {
            if (cards[i].aadharNo == ano) {
                // Shift all cards after deleted one to the left
                for (int j = i; j < cardCount - 1; j++) {
                    cards[j] = cards[j + 1];
                }

                cardCount--;
                cout << "Aadhar Card deleted successfully!\n";
                return;
            }
        }

        cout << "Aadhar Card with number " << ano << " not found.\n";
    }

    // Menu
    void showMenu() {
        int choice;

        do {
            cout << "\n--- Aadhar Card Management System ---\n";
            cout << "1. Insert Aadhar Card\n";
            cout << "2. Display All Aadhar Cards\n";
            cout << "3. Find Aadhar Card by Number\n";
            cout << "4. Update Aadhar Card\n";
            cout << "5. Delete Aadhar Card\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    insertAadhar();
                    break;
                case 2:
                    displayAadharCards();
                    break;
                case 3:
                    findAadharByNumber();
                    break;
                case 4:
                    updateAadhar();
                    break;
                case 5:
                    deleteAadhar();
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
    AadharManagement am;
    am.showMenu();
    return 0;
}
