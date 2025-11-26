#include <iostream>
using namespace std;

// Display sparse matrix in triplet form
void display(int s[][3]) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i <= s[0][2]; i++) {
        cout << s[i][0] << "\t" << s[i][1] << "\t" << s[i][2] << endl;
    }
}

// Simple Transpose
void simpleTranspose(int s[][3], int t[][3]) {
    int k = 1;
    t[0][0] = s[0][1];  
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];

    for (int col = 0; col < s[0][1]; col++) {
        for (int i = 1; i <= s[0][2]; i++) {
            if (s[i][1] == col) {
                t[k][0] = s[i][1];
                t[k][1] = s[i][0];
                t[k][2] = s[i][2];
                k++;
            }
        }
    }
}

int main() {
    int m, n, nonzero = 0;
    int a[10][10];
    int s[50][3], t[50][3];

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0)
                nonzero++;
        }
    }

    // Create sparse matrix
    s[0][0] = m;
    s[0][1] = n;
    s[0][2] = nonzero;

    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse Matrix:";
    display(s);

    simpleTranspose(s, t);
    cout << "\nSimple Transpose:";
    display(t);

    return 0;
}

