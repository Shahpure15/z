#include <iostream>
using namespace std;

struct Student {
    int roll;
    char name[20];
    float sgpa;
    char dept[10];
};

int main() {
    Student s[15] = {
        {5,"Amit",8.2,"COMP"},{1,"Riya",9.1,"ENTC"},{12,"John",7.8,"COMP"},
        {7,"Sara",9.4,"MECH"},{4,"Neha",8.9,"COMP"},{15,"Tina",6.5,"CIVIL"},
        {3,"Kiran",9.7,"COMP"},{9,"Om",7.2,"ENTC"},{13,"Pooja",8.4,"COMP"},
        {6,"Zara",9.0,"MECH"},{2,"Rohan",6.9,"CIVIL"},{8,"Meera",7.5,"COMP"},
        {11,"Ajay",8.0,"COMP"},{14,"Sneha",9.3,"ENTC"},{10,"Dev",8.6,"COMP"}
    };

    // Bubble sort by roll
    for (int i=0; i<14; i++) {
        for (int j=0; j<14-i; j++) {
            if (s[j].roll > s[j+1].roll) {
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    cout << "Sorted by Roll Number:\n";
    for (int i=0; i<15; i++)
        cout << s[i].roll<<"  "<<s[i].name<<"  "<<s[i].sgpa<<"  "<<s[i].dept<<endl;
}

