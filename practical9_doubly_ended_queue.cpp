#include <iostream>
using namespace std;

#define MAX 10

class Deque {
    int dq[MAX];
    int front, rear;

public:
    Deque() {
        front = rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void addFront(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at front.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        dq[front] = x;
    }

    void addRear(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot insert at rear.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dq[rear] = x;
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Underflow! No element to delete.\n";
            return;
        }
        cout << "Removed from front: " << dq[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Underflow! No element to delete.\n";
            return;
        }
        cout << "Removed from rear: " << dq[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty.\n";
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << dq[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Deque D;
    int mainChoice, opt, value;

    while (true) {
        cout << "\n=== DEQUE MENU ===\n";
        cout << "1. Input Restricted Deque\n";
        cout << "2. Output Restricted Deque\n";
        cout << "3. Exit\n";
        cout << "Select option: ";
        cin >> mainChoice;

        if (mainChoice == 3) break;

        while (true) {
            if (mainChoice == 1) {
                cout << "\n--- INPUT RESTRICTED DEQUE ---\n";
                cout << "1. Insert Rear\n2. Delete Front\n3. Delete Rear\n4. Display\n5. Back\n";
            }
            else {
                cout << "\n--- OUTPUT RESTRICTED DEQUE ---\n";
                cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Display\n5. Back\n";
            }

            cout << "Enter choice: ";
            cin >> opt;

            if (opt == 5) break;

            switch (opt) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    if (mainChoice == 1) D.addRear(value);
                    else D.addFront(value);
                    break;

                case 2:
                    if (mainChoice == 1) D.removeFront();
                    else {
                        cout << "Enter value: ";
                        cin >> value;
                        D.addRear(value);
                    }
                    break;

                case 3:
                    if (mainChoice == 1) D.removeRear();
                    else D.removeFront();
                    break;

                case 4:
                    D.display();
                    break;

                default:
                    cout << "Invalid choice!\n";
            }
        }
    }

    return 0;
}
