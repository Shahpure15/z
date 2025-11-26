#include <iostream>
#include <cstring>
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

    // Sort by name
    for (int i=1; i<15; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }

    char keyname[20];
    cout << "Enter name to search: ";
    cin >> keyname;

    int low = 0, high = 14, mid;
    bool found = false;

    while (low <= high) {
        mid = (low + high) / 2;

        int cmp = strcmp(s[mid].name, keyname);

        if (cmp == 0) {
            found = true;
            cout << s[mid].name<<" "<<s[mid].roll<<" "<<s[mid].sgpa<<" "<<s[mid].dept<<endl;
            break;
        }
        else if (cmp > 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (!found) cout << "Name Not Found!";
}

