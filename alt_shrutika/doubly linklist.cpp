#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() { head = NULL; }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL, NULL};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, NULL, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        if (temp->prev) temp->prev->next = NULL;
        else head = NULL;
        delete temp;
    }

    // Traverse forward
    void display() {
        if (!head) { cout << "List is empty\n"; return; }
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search for a value
    void search(int key) {
        Node* temp = head; int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found " << key << " at position " << pos << "\n";
                return;
            }
            temp = temp->next; pos++;
        }
        cout << key << " not found\n";
    }
};

//  Main 
int main() {
    DoublyLinkedList dlist;

    dlist.insertAtEnd(10);
    dlist.insertAtEnd(20);
    dlist.insertAtBeginning(5);
    dlist.display();

    dlist.search(20);
    dlist.deleteFromBeginning();
    dlist.display();

    dlist.deleteFromEnd();
    dlist.display();

    return 0;
}

