#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct DNode {
    int marks;
    DNode* prev;
    DNode* next;
};

// Create and return new node
DNode* newNode(int val) {
    DNode* p = new DNode;
    p->marks = val;
    p->prev = p->next = NULL;
    return p;
}

// Insert at end
void append(DNode*& head, int val) {
    DNode* p = newNode(val);
    if (head == NULL) {
        head = p;
        return;
    }
    DNode* t = head;
    while (t->next != NULL) t = t->next;
    t->next = p;
    p->prev = t;
}

// Display list forward
void show(DNode* h) {
    while (h != NULL) {
        cout << h->marks << " ";
        h = h->next;
    }
    cout << endl;
}

// Bubble Sort on Doubly Linked List
void bubbleSort(DNode* head) {
    if (!head) return;
    
    bool change;
    DNode* last = NULL;

    do {
        change = false;
        DNode* t = head;

        while (t->next != last) {
            if (t->marks > t->next->marks) {
                swap(t->marks, t->next->marks);
                change = true;
            }
            t = t->next;
        }
        last = t;
    } while (change);
}

// Merge two sorted DLLs
DNode* mergeSorted(DNode* a, DNode* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->marks <= b->marks) {
        a->next = mergeSorted(a->next, b);
        if (a->next) a->next->prev = a;
        a->prev = NULL;
        return a;
    } else {
        b->next = mergeSorted(a, b->next);
        if (b->next) b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

// Main
int main() {
    DNode* A = NULL;
    DNode* B = NULL;

    int n1, n2, val;

    cout << "Enter count of students in List A: ";
    cin >> n1;
    cout << "Enter marks for List A:\n";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        append(A, val);
    }

    cout << "\nEnter count of students in List B: ";
    cin >> n2;
    cout << "Enter marks for List B:\n";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        append(B, val);
    }

    cout << "\nList A before sorting: "; show(A);
    cout << "List B before sorting: "; show(B);

    bubbleSort(A);
    bubbleSort(B);

    cout << "\nList A after sorting: "; show(A);
    cout << "List B after sorting: "; show(B);

    DNode* result = mergeSorted(A, B);
    cout << "\nMerged Sorted Marks List: ";
    show(result);

    return 0;
}
