#include <iostream>
#include <string>
using namespace std;

struct Item {
    int code;
    string name;
    int qty;
    float price;
    Item* next;
};

class BillingSystem {
    Item* head;

public:
    BillingSystem() {
        head = NULL;
    }

    void addItem() {
        Item* temp = new Item;
        cout << "\nEnter Item Code: ";
        cin >> temp->code;
        cin.ignore();
        cout << "Enter Item Name: ";
        getline(cin, temp->name);
        cout << "Enter Quantity: ";
        cin >> temp->qty;
        cout << "Enter Price: ";
        cin >> temp->price;

        temp->next = NULL;

        if(head == NULL)
            head = temp;
        else {
            Item* p = head;
            while(p->next != NULL) p = p->next;
            p->next = temp;
        }
        cout << "\nItem Added Successfully!\n";
    }

    void displayItems() {
        if(head == NULL) {
            cout << "\nNo Items Found!\n";
            return;
        }
        Item* p = head;
        cout << "\n--- Billing Records ---\n";
        while(p != NULL) {
            cout << "\nCode: " << p->code;
            cout << "\nName: " << p->name;
            cout << "\nQuantity: " << p->qty;
            cout << "\nPrice: " << p->price;
            cout << "\n-----------------------";
            p = p->next;
        }
        cout << endl;
    }

    void searchItem() {
        if(head == NULL) { cout << "\nNo Items!\n"; return; }
        int c;
        cout << "\nEnter Item Code to Search: ";
        cin >> c;

        Item* p = head;
        while(p != NULL) {
            if(p->code == c) {
                cout << "\nItem Found!";
                cout << "\nName: " << p->name;
                cout << "\nQty: " << p->qty;
                cout << "\nPrice: " << p->price << endl;
                return;
            }
            p = p->next;
        }
        cout << "\nItem Not Found!\n";
    }

    void updateItem() {
        if(head == NULL) { cout << "\nNo Records!\n"; return; }
        int c;
        cout << "\nEnter Item Code to Update: ";
        cin >> c;

        Item* p = head;
        while(p != NULL) {
            if(p->code == c) {
                cout << "\nEnter New Name: ";
                cin.ignore();
                getline(cin, p->name);
                cout << "Enter New Quantity: ";
                cin >> p->qty;
                cout << "Enter New Price: ";
                cin >> p->price;
                cout << "\nUpdated Successfully!\n";
                return;
            }
            p = p->next;
        }
        cout << "\nItem Not Found!\n";
    }

    void deleteItem() {
        if(head == NULL) { cout << "\nList Empty!\n"; return; }

        int c;
        cout << "\nEnter Item Code to Delete: ";
        cin >> c;

        Item *p = head, *prev = NULL;

        if(p->code == c) {
            head = p->next;
            delete p;
            cout << "\nItem Deleted!\n";
            return;
        }

        while(p != NULL && p->code != c) {
            prev = p;
            p = p->next;
        }

        if(p == NULL) {
            cout << "\nItem Not Found!\n";
            return;
        }

        prev->next = p->next;
        delete p;
        cout << "\nItem Removed!\n";
    }

    void sortItems() {
        if(head == NULL || head->next == NULL) {
            cout << "\n Not enough records to sort\n";
            return;
        }

        for(Item* i = head; i->next != NULL; i = i->next) {
            for(Item* j = i->next; j != NULL; j = j->next) {
                if(i->code > j->code) {
                    swap(i->code, j->code);
                    swap(i->name, j->name);
                    swap(i->qty, j->qty);
                    swap(i->price, j->price);
                }
            }
        }
        cout << "\nRecords Sorted by Item Code!\n";
    }
};

int main() {
    BillingSystem b;
    int ch;

    do {
        cout << "\n===== Mall Billing System =====";
        cout << "\n1. Add Item";
        cout << "\n2. Display Items";
        cout << "\n3. Search Item";
        cout << "\n4. Update Item";
        cout << "\n5. Delete Item";
        cout << "\n6. Sort Items";
        cout << "\n7. Exit";
        cout << "\nEnter Choice: ";
        cin >> ch;

        switch(ch) {
            case 1: b.addItem(); break;
            case 2: b.displayItems(); break;
            case 3: b.searchItem(); break;
            case 4: b.updateItem(); break;
            case 5: b.deleteItem(); break;
            case 6: b.sortItems(); break;
            case 7: cout << "\nThank You!\n"; break;
            default: cout << "\nInvalid Option!\n";
        }
    } while(ch != 7);

    return 0;
}
