#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int roll;
    char name[20];
    float sgpa;
    char dept[10];
};

int fibSearch(Student s[], int n, char key[]) {
    int fib2 = 0;   // (m-2)
    int fib1 = 1;   // (m-1)
    int fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = (offset + fib2 < n-1) ? offset + fib2 : n-1;

        if (strcmp(s[i].dept, key) < 0) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (strcmp(s[i].dept, key) > 0) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
            return i;
    }

    if (fib1 && strcmp(s[offset+1].dept,key)==0)
        return offset+1;

    return -1;
}

int main() {
    Student s[15] = {
        {5,"Amit",8.2,"COMP"},{1,"Riya",9.1,"ENTC"},{12,"John",7.8,"COMP"},
        {7,"Sara",9.4,"MECH"},{4,"Neha",8.9,"COMP"},{15,"Tina",6.5,"CIVIL"},
        {3,"Kiran",9.7,"COMP"},{9,"Om",7.2,"ENTC"},{13,"Pooja",8.4,"COMP"},
        {6,"Zara",9.0,"MECH"},{2,"Rohan",6.9,"CIVIL"},{8,"Meera",7.5,"COMP"},
        {11,"Ajay",8.0,"COMP"},{14,"Sneha",9.3,"ENTC"},{10,"Dev",8.6,"COMP"}
    };

    // Sort by dept (required for Fibonacci Search)
    for (int i=1; i<15; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].dept, key.dept) > 0) {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }

    int pos = fibSearch(s, 15, "COMP");

    if (pos == -1) cout << "No student in COMP dept\n";
    else {
        cout << "Students in COMP department:\n";
        for (int i=pos; i<15; i++) {
            if (strcmp(s[i].dept,"COMP")==0)
                cout << s[i].name<<" "<<s[i].roll<<" "<<s[i].sgpa<<" "<<s[i].dept<<endl;
        }
    }
}

