#include <iostream>
using namespace std;

struct Item {
    int id;
    string name;
    float price;
    Item* next;
};

Item* head = NULL;

// Insert
void insertItem() {
    Item* p = new Item();
    cout << "Enter Item ID: ";
    cin >> p->id;
    cout << "Enter Item Name: ";
    cin >> p->name;
    cout << "Enter Price: ";
    cin >> p->price;
    p->next = NULL;

    if (!head) head = p;
    else {
        Item* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = p;
    }
    cout << "Item Added.\n";
}

// Display
void displayItem() {
    Item* temp = head;
    cout << "\n--- Item List ---\n";
    while (temp) {
        cout << "ID: " << temp->id << "  Name: " << temp->name
             << "  Price: " << temp->price << endl;
        temp = temp->next;
    }
}

// Search
void searchItem() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    Item* temp = head;
    while (temp) {
        if (temp->id == id) {
            cout << "Found: " << temp->name << "  Price: " << temp->price << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not found.\n";
}

// Update
void updateItem() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    Item* temp = head;
    while (temp) {
        if (temp->id == id) {
            cout << "New Name: ";
            cin >> temp->name;
            cout << "New Price: ";
            cin >> temp->price;
            cout << "Updated.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not found.\n";
}

// Sort by price
void sortItem() {
    for (Item* i = head; i && i->next; i++) {
        for (Item* j = i->next; j; j++) {
            if (i->price > j->price) {
                swap(i->id, j->id);
                swap(i->name, j->name);
                swap(i->price, j->price);
            }
        }
    }
    cout << "Items Sorted by Price.\n";
}

// Delete
void deleteItem() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    if (!head) return;

    if (head->id == id) {
        Item* t = head;
        head = head->next;
        delete t;
        cout << "Deleted.\n";
        return;
    }

    Item* temp = head;
    while (temp->next && temp->next->id != id)
        temp = temp->next;

    if (!temp->next) return;

    Item* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Deleted.\n";
}

int main() {
    int ch;

    do {
        cout << "\n--- Mall Billing System ---";
        cout << "\n1.Insert\n2.Display\n3.Search\n4.Update\n5.Sort\n6.Delete\n7.Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1: insertItem(); break;
            case 2: displayItem(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: sortItem(); break;
            case 6: deleteItem(); break;
        }

    } while (ch != 7);

    return 0;
}

