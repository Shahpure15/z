#include <iostream>
using namespace std;

struct Aadhar {
    long long aadharNo;
    string name;
    string address;
};

int main() {
    Aadhar arr[100];
    int n = 0;
    int choice;

    do {
        cout << "\n===== AADHAR CARD MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Aadhar Record";
        cout << "\n2. Display All Records";
        cout << "\n3. Insert Record at Position";
        cout << "\n4. Update Aadhar Record";
        cout << "\n5. Delete Aadhar Record";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            // ADD
            case 1: {
                int count;
                cout << "\nHow many records to add? ";
                cin >> count;

                for (int i = 0; i < count; i++) {
                    cout << "\nEnter Aadhar Number: ";
                    cin >> arr[n].aadharNo;
                    cout << "Enter Name: ";
                    cin >> arr[n].name;
                    cout << "Enter Address: ";
                    cin >> arr[n].address;
                    n++;
                }
                break;
            }

            // DISPLAY
            case 2: {
                if (n == 0) {
                    cout << "\nNo records available.\n";
                } else {
                    cout << "\n--- Aadhar Records ---\n";
                    for (int i = 0; i < n; i++) {
                        cout << "\nRecord " << i+1;
                        cout << "\nAadhar No: " << arr[i].aadharNo;
                        cout << "\nName: " << arr[i].name;
                        cout << "\nAddress: " << arr[i].address << endl;
                    }
                }
                break;
            }

            // INSERT
            case 3: {
                int pos;
                cout << "\nEnter position to insert (1 to " << n+1 << "): ";
                cin >> pos;

                if (pos < 1 || pos > n + 1) {
                    cout << "\nInvalid Position!";
                } else {
                    for (int i = n; i >= pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    cout << "\nEnter Aadhar Number: ";
                    cin >> arr[pos - 1].aadharNo;
                    cout << "Enter Name: ";
                    cin >> arr[pos - 1].name;
                    cout << "Enter Address: ";
                    cin >> arr[pos - 1].address;
                    n++;
                    cout << "\nRecord Inserted!";
                }
                break;
            }

            // UPDATE
            case 4: {
                long long id;
                cout << "\nEnter Aadhar Number to Update: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i].aadharNo == id) {
                        cout << "Enter New Name: ";
                        cin >> arr[i].name;
                        cout << "Enter New Address: ";
                        cin >> arr[i].address;
                        cout << "\nRecord Updated!";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "\nAadhar Number Not Found!";
                break;
            }

            // DELETE
            case 5: {
                long long id;
                cout << "\nEnter Aadhar Number to Delete: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i].aadharNo == id) {
                        for (int j = i; j < n - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        n--;
                        cout << "\nRecord Deleted!";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "\nAadhar Number Not Found!";
                break;
            }

            case 6:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while (choice != 6);

    return 0;
}

