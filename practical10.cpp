#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rno;
    string nm, dept;
    float sgpa;

    void show() {
        cout << rno << "\t" << nm << "\t" << dept << "\t" << sgpa << endl;
    }
};

// Bubble Sort by Roll No (Ascending)
void bubbleRollSort(Student a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j].rno > a[j+1].rno) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

// Insertion Sort by Name (A–Z)
void insertionNameSort(Student a[], int n) {
    for(int i = 1; i < n; i++) {
        Student key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j].nm > key.nm) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// Quick Sort (SGPA High to Low)
int partition(Student a[], int low, int high) {
    float pivot = a[high].sgpa;
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(a[j].sgpa > pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}
void quickSGPASort(Student a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quickSGPASort(a, low, pi - 1);
        quickSGPASort(a, pi + 1, high);
    }
}

// Linear Search by SGPA
void findBySGPA(Student a[], int n, float x) {
    bool flag = false;
    cout << "\nStudents with SGPA " << x << ":\n";
    cout << "Roll\tName\tDept\tSGPA\n";
    for(int i = 0; i < n; i++) {
        if(a[i].sgpa == x) {
            a[i].show();
            flag = true;
        }
    }
    if(!flag) cout << "No records found.\n";
}

// Binary Search by Name (non-recursive)
void binarySearchName(Student a[], int n, string key) {
    insertionNameSort(a, n);
    int l = 0, r = n - 1;
    bool ok = false;
    while(l <= r) {
        int m = (l + r) / 2;
        if(a[m].nm == key) {
            ok = true;
            cout << "\nRecord Found:\nRoll\tName\tDept\tSGPA\n";
            a[m].show();
            break;
        }
        else if(a[m].nm < key) l = m + 1;
        else r = m - 1;
    }
    if(!ok) cout << "\nName not found.\n";
}

// Fibonacci Search by Department
int fibSearchDept(Student a[], int n, string key) {
    int f2 = 0, f1 = 1, f = f1 + f2;
    while(f < n) {
        f2 = f1; f1 = f; f = f1 + f2;
    }
    int offset = -1;

    while(f > 1) {
        int i = min(offset + f2, n-1);
        if(a[i].dept < key) {
            f = f1;
            f1 = f2;
            f2 = f - f1;
            offset = i;
        }
        else if(a[i].dept > key) {
            f = f2;
            f1 = f1 - f2;
            f2 = f - f1;
        }
        else return i;
    }
    if(f1 && a[offset+1].dept == key) return offset+1;
    return -1;
}

int main() {
    const int n = 15;
    Student s[n] = {
        {10,"Aarav","CSE",9.60}, {3,"Riya","IT",8.40}, {12,"Dev","ENTC",7.85},
        {1,"Kabir","CSE",9.10}, {8,"Isha","MECH",8.20}, {4,"Mihir","CIVIL",7.50},
        {5,"Sara","CSE",9.55}, {15,"Yash","IT",8.90}, {2,"Tara","AI",9.75},
        {7,"Om","CSE",8.30}, {11,"Anaya","MECH",7.80}, {6,"Rehan","ENTC",8.00},
        {9,"Neel","AI",9.20}, {13,"Pooja","CIVIL",7.95}, {14,"Vivek","IT",8.75}
    };

    cout << "--- Original Database ---\nRoll\tName\tDept\tSGPA\n";
    for(int i=0;i<n;i++) s[i].show();

    bubbleRollSort(s,n);
    cout << "\n--- Sorted by Roll No (Bubble Sort) ---\nRoll\tName\tDept\tSGPA\n";
    for(int i=0;i<n;i++) s[i].show();

    insertionNameSort(s,n);
    cout << "\n--- Sorted by Name (Insertion Sort) ---\nRoll\tName\tDept\tSGPA\n";
    for(int i=0;i<n;i++) s[i].show();

    quickSGPASort(s,0,n-1);
    cout << "\n--- Top 10 by SGPA (Quick Sort) ---\n";
    for(int i=0;i<10;i++) s[i].show();

    float target;
    cout << "\nEnter SGPA to search: ";
    cin >> target;
    findBySGPA(s,n,target);

    string key;
    cout << "\nEnter Name to search: ";
    cin >> key;
    binarySearchName(s,n,key);

    string dep;
    cout << "\nEnter Dept to check (Fibonacci Search): ";
    cin >> dep;
    int pos = fibSearchDept(s,n,dep);
    if(pos != -1) {
        cout << "Dept Found. Example Student:\n";
        s[pos].show();
    } else cout << "No student from that department.\n";

    return 0;
}
