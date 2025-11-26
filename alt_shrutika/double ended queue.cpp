//double ended queue
#include <iostream>
using namespace std;

#define SIZE 10

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    // ------------------- Normal Insert at Front ---------------------
    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }
        if (front == -1) {  // first element
            front = rear = 0;
        }
        else if (front == 0) {
            front = SIZE - 1;
        }
        else {
            front--;
        }
        arr[front] = x;
        cout << x << " inserted at front\n";
    }

    // ------------------- Normal Insert at Rear ----------------------
    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }
        if (front == -1) { // first element
            front = rear = 0;
        }
        else if (rear == SIZE - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        cout << x << " inserted at rear\n";
    }

    // ------------------- Delete from Front --------------------------
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << arr[front] << " deleted from front\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == SIZE - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    // ------------------- Delete from Rear ---------------------------
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << arr[rear] << " deleted from rear\n";

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = SIZE - 1;
        }
        else {
            rear--;
        }
    }

    // ------------------- Display Deque ------------------------------
    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deque Elements: ";
        int i = front;

        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << arr[rear] << endl;
    }
};


// ================== MAIN PROGRAM FOR SCENARIOS =====================
int main() {
    Deque dq;
    int choice, x, type;

    cout << "\n***** SHOPPING MALL DEQUE SYSTEM *****\n";
    cout << "1. Input Restricted Deque\n";
    cout << "2. Output Restricted Deque\n";
    cout << "Enter your choice: ";
    cin >> type;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        // ------------------------------------------------------------
        //  Input Restricted Deque: insertion only at REAR
        // ------------------------------------------------------------
        case 1:
            if (type == 1) {
                cout << "Front insertion not allowed in Input Restricted Deque!\n";
            } else {
                cout << "Enter value: ";
                cin >> x;
                dq.insertFront(x);
            }
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            dq.insertRear(x);
            break;

        // ------------------------------------------------------------
        //  Output Restricted Deque: deletion only from FRONT
        // ------------------------------------------------------------
        case 3:
            dq.deleteFront();
            break;

        case 4:
            if (type == 2) {
                cout << "Rear deletion not allowed in Output Restricted Deque!\n";
            } else {
                dq.deleteRear();
            }
            break;

        case 5:
            dq.display();
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
