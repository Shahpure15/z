#include <iostream>
#include <string>
using namespace std;

// Node structure for Placement records
struct Placement {
    int studentID;
    string studentName;
    string company;
    string package;  // Salary package
    string position;
    Placement* next;
};

class PlacementSystem {
    Placement* head;

public:
    PlacementSystem() {
        head = NULL;
    }

    // Insert new placement record
    void insertRecord() {
        Placement* newRecord = new Placement;
        
        cout << "\nEnter Student ID: ";
        cin >> newRecord->studentID;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, newRecord->studentName);
        cout << "Enter Company Name: ";
        getline(cin, newRecord->company);
        cout << "Enter Package (e.g., 5 LPA): ";
        getline(cin, newRecord->package);
        cout << "Enter Position: ";
        getline(cin, newRecord->position);

        newRecord->next = NULL;

        // Insert at end
        if (head == NULL) {
            head = newRecord;
        } else {
            Placement* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newRecord;
        }

        cout << "\nPlacement Record Added Successfully!\n";
    }

    // Display all placement records
    void displayRecords() {
        if (head == NULL) {
            cout << "\nNo Placement Records Found!\n";
            return;
        }

        Placement* temp = head;
        cout << "\nPlacement Record\n";
        while (temp != NULL) {
            cout << "\nStudent ID: " << temp->studentID;
            cout << "\nStudent Name: " << temp->studentName;
            cout << "\nCompany: " << temp->company;
            cout << "\nPackage: " << temp->package;
            cout << "\nPosition: " << temp->position;
            temp = temp->next;
        }
        cout << endl;
    }

    // Search placement record by student ID
    void searchRecord() {
        if (head == NULL) {
            cout << "\nNo Records Available!\n";
            return;
        }

        int id;
        cout << "\nEnter Student ID to Search: ";
        cin >> id;

        Placement* temp = head;
        while (temp != NULL) {
            if (temp->studentID == id) {
                cout << "\n--- Record Found ---";
                cout << "\nStudent ID: " << temp->studentID;
                cout << "\nStudent Name: " << temp->studentName;
                cout << "\nCompany: " << temp->company;
                cout << "\nPackage: " << temp->package;
                cout << "\nPosition: " << temp->position << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "\nRecord Not Found!\n";
    }

    // Update placement record
    void updateRecord() {
        if (head == NULL) {
            cout << "\nNo Records to Update!\n";
            return;
        }

        int id;
        cout << "\nEnter Student ID to Update: ";
        cin >> id;

        Placement* temp = head;
        while (temp != NULL) {
            if (temp->studentID == id) {
                cin.ignore();
                cout << "\nEnter New Student Name: ";
                getline(cin, temp->studentName);
                cout << "Enter New Company: ";
                getline(cin, temp->company);
                cout << "Enter New Package: ";
                getline(cin, temp->package);
                cout << "Enter New Position: ";
                getline(cin, temp->position);

                cout << "\nRecord Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "\nRecord Not Found!\n";
    }

    // Delete placement record
    void deleteRecord() {
        if (head == NULL) {
            cout << "\nNo Records to Delete!\n";
            return;
        }

        int id;
        cout << "\nEnter Student ID to Delete: ";
        cin >> id;

        Placement *temp = head, *prev = NULL;

        // If head node is to be deleted
        if (temp != NULL && temp->studentID == id) {
            head = temp->next;
            delete temp;
            cout << "\nRecord Deleted Successfully!\n";
            return;
        }

        // Search for the record to be deleted
        while (temp != NULL && temp->studentID != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\nRecord Not Found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "\nRecord Deleted Successfully!\n";
    }

    // Sort records by Student ID
    void sortRecords() {
        if (head == NULL || head->next == NULL) {
            cout << "\nNot enough records to sort!\n";
            return;
        }

        for (Placement* i = head; i->next != NULL; i = i->next) {
            for (Placement* j = i->next; j != NULL; j = j->next) {
                if (i->studentID > j->studentID) {
                    swap(i->studentID, j->studentID);
                    swap(i->studentName, j->studentName);
                    swap(i->company, j->company);
                    swap(i->package, j->package);
                    swap(i->position, j->position);
                }
            }
        }

        cout << "\nRecords Sorted by Student ID!\n";
    }

    // List all students placed in a specific company
    void listByCompany() {
        if (head == NULL) {
            cout << "\nNo Records Available!\n";
            return;
        }

        string comp;
        cout << "\nEnter Company Name: ";
        cin.ignore();
        getline(cin, comp);

        Placement* temp = head;
        bool found = false;

        cout << "\n--- Students Placed in " << comp << " ---\n";
        while (temp != NULL) {
            if (temp->company == comp) {
                cout << "\nStudent ID: " << temp->studentID;
                cout << "\nStudent Name: " << temp->studentName;
                cout << "\nPackage: " << temp->package;
                cout << "\nPosition: " << temp->position;
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\nNo students placed in " << comp << "!\n";
        }
    }
};

int main() {
    PlacementSystem ps;
    int choice;

    do {
        cout << "\nPlacement Information System";
        cout << "\n1. Insert Placement Record";
        cout << "\n2. Display All Records";
        cout << "\n3. Search Record by Student ID";
        cout << "\n4. Update Record";
        cout << "\n5. Delete Record";
        cout << "\n6. Sort Records by Student ID";
        cout << "\n7. List Students by Company";
        cout << "\n8. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ps.insertRecord(); break;
            case 2: ps.displayRecords(); break;
            case 3: ps.searchRecord(); break;
            case 4: ps.updateRecord(); break;
            case 5: ps.deleteRecord(); break;
            case 6: ps.sortRecords(); break;
            case 7: ps.listByCompany(); break;
            case 8: cout << "\nExiting System...\n"; break;
            default: cout << "\nInvalid Choice!\n";
        }
    } while (choice != 8);

    return 0;
}
