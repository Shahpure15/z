#include <iostream>
#include <string>
using namespace std;

// linear probing
class HashLinear {
    string table[6];
    bool occupied[6];

public:
    HashLinear() {
        for(int i = 0; i < 6; i++) {
            table[i] = "";
            occupied[i] = false;
        }
    }

    int hashFunc(int key) {
        return key % 6;
    }

    void insert(string flavor, int key) {
        int idx = hashFunc(key);
        int start = idx;
        
        // Linear probing
        while(occupied[idx]) {
            cout << "Collision at " << idx << ", probing..." << endl;
            idx = (idx + 1) % 6;
            if(idx == start) {
                cout << "Table full!" << endl;
                return;
            }
        }
        
        table[idx] = flavor;
        occupied[idx] = true;
        cout << flavor << " (key=" << key << ") inserted at index " << idx << endl;
    }

    void display() {
        cout << "\nHash Table (Linear Probing):\n";
        cout << "Index\tFlavor\n";
        for(int i = 0; i < 6; i++) {
            if(occupied[i])
                cout << i << "\t" << table[i] << endl;
            else
                cout << i << "\t---" << endl;
        }
    }
};

// seperate chaining
struct Node {
    int marks;
    Node* next;
};

class HashChaining {
    Node* table[20];

public:
    HashChaining() {
        for(int i = 0; i < 20; i++)
            table[i] = NULL;
    }

    int hashFunc(int key) {
        return key % 20;
    }

    void insert(int marks) {
        int idx = hashFunc(marks);
        Node* newNode = new Node;
        newNode->marks = marks;
        newNode->next = NULL;

        if(table[idx] == NULL) {
            table[idx] = newNode;
            cout << "Marks " << marks << " inserted at index " << idx << endl;
        } else {
            cout << "Collision at " << idx << " for marks " << marks << ", using chaining..." << endl;
            Node* temp = table[idx];
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        cout << "\nHash Table (Separate Chaining):\n";
        cout << "Index\tMarks Chain\n";
        for(int i = 0; i < 20; i++) {
            cout << i << "\t";
            if(table[i] == NULL)
                cout << "---";
            else {
                Node* temp = table[i];
                while(temp != NULL) {
                    cout << temp->marks;
                    if(temp->next != NULL)
                        cout << " -> ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
};
//qudratic probing
class HashQuadratic {
    int table[11];
    bool occupied[11];

public:
    HashQuadratic() {
        for(int i = 0; i < 11; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    int hashFunc(int key) {
        return key % 11;
    }

    void insert(int mangoes) {
        int idx = hashFunc(mangoes);
        int i = 0;
        
        while(occupied[idx]) {
            cout << "Collision at " << idx << " for value " << mangoes << endl;
            i++;
            idx = (hashFunc(mangoes) + i * i) % 11;
            
            if(i >= 11) {
                cout << "Table full, cannot insert " << mangoes << endl;
                return;
            }
        }
        
        table[idx] = mangoes;
        occupied[idx] = true;
        cout << "Mangoes " << mangoes << " inserted at index " << idx << endl;
    }

    void display() {
        cout << "\nHash Table (Quadratic Probing):\n";
        cout << "Index\tMangoes\n";
        for(int i = 0; i < 11; i++) {
            if(occupied[i])
                cout << i << "\t" << table[i] << endl;
            else
                cout << i << "\t---" << endl;
        }
    }
};

// main funct
int main() {
    int choice;
    
    do {
        cout << "\n\n========== HASHING PRACTICAL ==========\n";
        cout << "1. Linear Probing (Cold Drink Shop)\n";
        cout << "2. Separate Chaining (Student Marks)\n";
        cout << "3. Quadratic Probing (Mango Shop)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                HashLinear h;
                int n, key;
                string flavor;
                
                cout << "\n--- Cold Drink Corner (Linear Probing) ---\n";
                cout << "Enter number of flavors: ";
                cin >> n;
                
                for(int i = 0; i < n; i++) {
                    cout << "Enter flavor name: ";
                    cin >> flavor;
                    cout << "Enter key: ";
                    cin >> key;
                    h.insert(flavor, key);
                }
                h.display();
                break;
            }
            
            case 2: {
                HashChaining h;
                int marks[] = {33,56,78,12,10,67,89,99,100,23,45,71,39,62,59,90,91,20,75,66};
                
                cout << "\n--- Student Marks (Separate Chaining) ---\n";
                for(int i = 0; i < 20; i++) {
                    h.insert(marks[i]);
                }
                h.display();
                break;
            }
            
            case 3: {
                HashQuadratic h;
                int mangoes[] = {25,15,10,5,11,19,16,36,42,28,32};
                
                cout << "\n--- Mango Shop (Quadratic Probing) ---\n";
                for(int i = 0; i < 11; i++) {
                    cout << "\nCategory " << (i+1) << ":\n";
                    h.insert(mangoes[i]);
                }
                h.display();
                break;
            }
            
            case 0:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 0);
    
    return 0;
}
