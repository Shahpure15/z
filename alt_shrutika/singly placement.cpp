#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    float cgpa;
    Student* next;
};

Student* head = NULL;

// Insert at end
void insertRecord() {
    Student* p = new Student();
    cout << "\nEnter Roll No: ";
    cin >> p->roll;
    cout << "Enter Name: ";
    cin >> p->name;
    cout << "Enter CGPA: ";
    cin >> p->cgpa;
    p->next = NULL;

    if (head == NULL)
        head = p;
    else {
        Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    cout << "Record Inserted.\n";
}

// Display
void display() {
    if (!head) {
        cout << "\nNo records.\n";
        return;
    }
    Student* temp = head;
    cout << "\n--- Placement Records ---\n";
    while (temp) {
        cout << "Roll: " << temp->roll
             << "  Name: " << temp->name
             << "  CGPA: " << temp->cgpa << endl;
        temp = temp->next;
    }
}

// Search
void searchRecord() {
    int r;
    cout << "Enter roll to search: ";
    cin >> r;
    Student* temp = head;
    while (temp) {
        if (temp->roll == r) {
            cout << "\nFound: " << temp->name << "  CGPA: " << temp->cgpa << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not found.\n";
}

// Update
void updateRecord() {
    int r;
    cout << "Enter roll to update: ";
    cin >> r;
    Student* temp = head;
    while (temp) {
        if (temp->roll == r) {
            cout << "Enter new name: ";
            cin >> temp->name;
            cout << "Enter new CGPA: ";
            cin >> temp->cgpa;
            cout << "Updated!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not found.\n";
}

// Sort by roll
void sortList() {
    if (!head) return;
    for (Student* i = head; i->next != NULL; i++) {
        for (Student* j = i->next; j != NULL; j++) {
            if (i->roll > j->roll) {
                swap(i->roll, j->roll);
                swap(i->name, j->name);
                swap(i->cgpa, j->cgpa);
            }
        }
    }
    cout << "List sorted.\n";
}

// Delete
void deleteRecord() {
    int r;
    cout << "Enter roll to delete: ";
    cin >> r;

    if (!head) return;

    if (head->roll == r) {
        Student* t = head;
        head = head->next;
        delete t;
        cout << "Deleted.\n";
        return;
    }

    Student* temp = head;
    while (temp->next && temp->next->roll != r)
        temp = temp->next;

    if (!temp->next) {
        cout << "Not found.\n";
        return;
    }

    Student* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Deleted.\n";
}

int main() {
    int ch;
    do {
        cout << "\n--- Placement Information System ---";
        cout << "\n1.Insert\n2.Display\n3.Search\n4.Update\n5.Sort\n6.Delete\n7.Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1: insertRecord(); break;
            case 2: display(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: sortList(); break;
            case 6: deleteRecord(); break;
            case 7: cout << "Exiting..."; break;
            default: cout << "Invalid!";
        }

    } while (ch != 7);

    return 0;
}

