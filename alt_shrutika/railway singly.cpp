#include <iostream>
using namespace std;

struct Passenger {
    int pnr;
    string name;
    string source, destination;
    Passenger* next;
};

Passenger* head = NULL;

// Insert passenger
void insertP() {
    Passenger* p = new Passenger();
    cout << "\nEnter PNR: ";
    cin >> p->pnr;
    cout << "Enter Name: ";
    cin >> p->name;
    cout << "Source: ";
    cin >> p->source;
    cout << "Destination: ";
    cin >> p->destination;
    p->next = NULL;

    if (!head) head = p;
    else {
        Passenger* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = p;
    }
    cout << "Ticket Booked.\n";
}

// Display
void displayP() {
    if (!head) {
        cout << "\nNo reservations.\n";
        return;
    }
    cout << "\n--- Reservation List ---\n";
    Passenger* temp = head;
    while (temp) {
        cout << "PNR: " << temp->pnr << "  Name: " << temp->name
             << "  " << temp->source << " -> " << temp->destination << endl;
        temp = temp->next;
    }
}

// Search
void searchP() {
    int id;
    cout << "Enter PNR to search: ";
    cin >> id;

    Passenger* temp = head;
    while (temp) {
        if (temp->pnr == id) {
            cout << "Found: " << temp->name << "  Journey: " 
                 << temp->source << " to " << temp->destination << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not found.\n";
}

// Update
void updateP() {
    int id;
    cout << "Enter PNR to update: ";
    cin >> id;

    Passenger* temp = head;
    while (temp) {
        if (temp->pnr == id) {
            cout << "New Name: ";
            cin >> temp->name;
            cout << "New Source: ";
            cin >> temp->source;
            cout << "New Destination: ";
            cin >> temp->destination;
            cout << "Updated.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not found.\n";
}

// Sort by PNR
void sortP() {
    for (Passenger* i = head; i && i->next; i++) {
        for (Passenger* j = i->next; j; j++) {
            if (i->pnr > j->pnr) {
                swap(i->pnr, j->pnr);
                swap(i->name, j->name);
                swap(i->source, j->source);
                swap(i->destination, j->destination);
            }
        }
    }
    cout << "Sorted.\n";
}

// Delete
void deleteP() {
    int id;
    cout << "Enter PNR to delete: ";
    cin >> id;

    if (!head) return;

    if (head->pnr == id) {
        Passenger* t = head;
        head = head->next;
        delete t;
        cout << "Deleted.\n";
        return;
    }

    Passenger* temp = head;
    while (temp->next && temp->next->pnr != id)
        temp = temp->next;

    if (!temp->next) {
        cout << "Not found.\n";
        return;
    }

    Passenger* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Deleted.\n";
}

int main() {
    int ch;
    do {
        cout << "\n--- Railway Reservation System ---";
        cout << "\n1.Book\n2.Display\n3.Search\n4.Update\n5.Sort\n6.Delete\n7.Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1: insertP(); break;
            case 2: displayP(); break;
            case 3: searchP(); break;
            case 4: updateP(); break;
            case 5: sortP(); break;
            case 6: deleteP(); break;
        }
    } while (ch != 7);

    return 0;
}

