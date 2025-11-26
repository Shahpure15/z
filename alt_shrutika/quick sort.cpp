#include <iostream>
using namespace std;

struct Student {
    int roll;
    char name[20];
    float sgpa;
    char dept[10];
};

int partition(Student s[], int low, int high) {
    float pivot = s[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].sgpa > pivot) {
            i++;
            Student temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    Student temp = s[i+1];
    s[i+1] = s[high];
    s[high] = temp;

    return i+1;
}

void quickSort(Student s[], int low, int high) {
    if (low < high) {
        int pi = partition(s, low, high);
        quickSort(s, low, pi-1);
        quickSort(s, pi+1, high);
    }
}

int main() {
    Student s[15] = {
        {5,"Amit",8.2,"COMP"},{1,"Riya",9.1,"ENTC"},{12,"John",7.8,"COMP"},
        {7,"Sara",9.4,"MECH"},{4,"Neha",8.9,"COMP"},{15,"Tina",6.5,"CIVIL"},
        {3,"Kiran",9.7,"COMP"},{9,"Om",7.2,"ENTC"},{13,"Pooja",8.4,"COMP"},
        {6,"Zara",9.0,"MECH"},{2,"Rohan",6.9,"CIVIL"},{8,"Meera",7.5,"COMP"},
        {11,"Ajay",8.0,"COMP"},{14,"Sneha",9.3,"ENTC"},{10,"Dev",8.6,"COMP"}
    };

    quickSort(s, 0, 14);

    cout << "\nTop 10 Toppers:\n";
    for (int i = 0; i < 10; i++)
        cout << s[i].name<<"  "<<s[i].sgpa<<"  "<<s[i].roll<<" "<<s[i].dept<<endl;
}

