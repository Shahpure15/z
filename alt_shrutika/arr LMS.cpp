#include <iostream>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

int main() {
    Book arr[100];
    int n = 0;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Insert Book at Position";
        cout << "\n4. Update Book Information";
        cout << "\n5. Delete Book";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            // ADD
            case 1: {
                int count;
                cout << "\nHow many books to add? ";
                cin >> count;

                for (int i = 0; i < count; i++) {
                    cout << "\nEnter Book ID: ";
                    cin >> arr[n].id;
                    cout << "Enter Title: ";
                    cin >> arr[n].title;
                    cout << "Enter Author: ";
                    cin >> arr[n].author;
                    n++;
                }
                break;
            }

            // DISPLAY
            case 2: {
                if (n == 0) {
                    cout << "\nNo books available.\n";
                } else {
                    cout << "\n--- Book List ---\n";
                    for (int i = 0; i < n; i++) {
                        cout << "\nBook " << i+1;
                        cout << "\nID: " << arr[i].id;
                        cout << "\nTitle: " << arr[i].title;
                        cout << "\nAuthor: " << arr[i].author << endl;
                    }
                }
                break;
            }

            // INSERT
            case 3: {
                int pos;
                cout << "\nEnter position to insert (1 to " << n+1 << "): ";
                cin >> pos;

                if (pos < 1 || pos > n+1) {
                    cout << "\nInvalid Position!";
                } else {
                    for (int i = n; i >= pos; i--) {
                        arr[i] = arr[i-1];
                    }

                    cout << "\nEnter Book ID: ";
                    cin >> arr[pos - 1].id;
                    cout << "Enter Title: ";
                    cin >> arr[pos - 1].title;
                    cout << "Enter Author: ";
                    cin >> arr[pos - 1].author;

                    n++;
                    cout << "\nBook Inserted!";
                }
                break;
            }

            // UPDATE
            case 4: {
                int id;
                cout << "\nEnter Book ID to Update: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i].id == id) {
                        cout << "Enter New Title: ";
                        cin >> arr[i].title;
                        cout << "Enter New Author: ";
                        cin >> arr[i].author;
                        cout << "\nBook Updated!";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "\nBook ID Not Found!";
                break;
            }

            // DELETE
            case 5: {
                int id;
                cout << "\nEnter Book ID to Delete: ";
                cin >> id;

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i].id == id) {
                        for (int j = i; j < n - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        n--;
                        cout << "\nBook Deleted!";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "\nBook ID Not Found!";
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

