#include <iostream>
using namespace std;

struct Node {
    int orderID;
    Node* next;
};

class PizzaParlor {
private:
    Node* front;
    Node* rear;
    int count;
    int maxOrders;

public:
    PizzaParlor(int m) {
        front = rear = NULL;
        count = 0;
        maxOrders = m;
    }

    // ------------------ Place Order (Enqueue) ------------------
    void placeOrder(int id) {
        if (count == maxOrders) {
            cout << "Cannot place order " << id 
                 << ". Maximum order limit reached.\n";
            return;
        }

        Node* temp = new Node;
        temp->orderID = id;

        if (front == NULL) {  
            front = rear = temp;
            temp->next = front;    // circular link
        }
        else {
            rear->next = temp;
            temp->next = front;
            rear = temp;
        }

        count++;
        cout << "Order " << id << " placed successfully.\n";
    }

    // ------------------ Serve Order (Dequeue) ------------------
    void serveOrder() {
        if (front == NULL) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Serving Order " << front->orderID << endl;

        if (front == rear) {   // only one order
            delete front;
            front = rear = NULL;
        }
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front;   // maintain circular link
            delete temp;
        }

        count--;
    }

    // ------------------ Display All Orders --------------------
    void display() {
        if (front == NULL) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        Node* temp = front;

        do {
            cout << temp->orderID << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

// --------------------------- MAIN -----------------------------
int main() {
    int maxOrders;
    cout << "Enter maximum number of orders Pizza Parlor can accept: ";
    cin >> maxOrders;

    PizzaParlor pp(maxOrders);

    int choice, id;

    do {
        cout << "\n--- Pizza Parlor Menu ---\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> id;
                pp.placeOrder(id);
                break;

            case 2:
                pp.serveOrder();
                break;

            case 3:
                pp.display();
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}

