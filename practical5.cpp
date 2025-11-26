#include <iostream>
using namespace std;

struct Order {
    int id;
    Order *next;
};

class PizzaQueue {
private:
    Order *front, *rear;
    int current, maxLimit;

public:
    PizzaQueue(int m) {
        front = rear = NULL;
        current = 0;
        maxLimit = m;
    }

    void takeOrder(int x) {
        if (current == maxLimit) {
            cout << "Order " << x << " rejected. Maximum limit reached!\n";
            return;
        }

        Order *node = new Order;
        node->id = x;
        node->next = NULL;

        if (front == NULL) {
            front = rear = node;
            rear->next = front;
        } else {
            rear->next = node;
            rear = node;
            rear->next = front;
        }

        current++;
        cout << "Order " << x << " placed.\n";
    }

    void serveOrder() {
        if (front == NULL) {
            cout << "No orders to serve!\n";
            return;
        }

        int servedID = front->id;

        if (front == rear) {
            delete front;
            front = rear = NULL;
        } else {
            Order *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        current--;
        cout << "Order " << servedID << " served.\n";
    }

    void viewOrders() {
        if (front == NULL) {
            cout << "No pending orders.\n";
            return;
        }

        cout << "Pending Orders: ";
        Order *temp = front;
        do {
            cout << temp->id << " ";
            temp = temp->next;
        } while (temp != front);
        cout << "\n";
    }
};

int main() {
    int M;
    cout << "Enter max number of orders allowed: ";
    cin >> M;

    PizzaQueue pq(M);
    int choice, orderID;

    do {
        cout << "\n==== Pizza Parlor System ====\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Select option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                pq.takeOrder(orderID);
                break;

            case 2:
                pq.serveOrder();
                break;

            case 3:
                pq.viewOrders();
                break;

            case 4:
                cout << "System Closed.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
