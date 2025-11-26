#include <iostream>
using namespace std;

// Display sparse matrix
void display(int s[][3]) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i <= s[0][2]; i++) {
        cout << s[i][0] << "\t" << s[i][1] << "\t" << s[i][2] << endl;
    }
}

// Fast Transpose
void fastTranspose(int s[][3], int t[][3]) {
    int rowTerms[20] = {0}, startingPos[20] = {0};
    int m = s[0][0], n = s[0][1], num = s[0][2];

    t[0][0] = n;
    t[0][1] = m;
    t[0][2] = num;

    for (int i = 1; i <= num; i++)
        rowTerms[s[i][1]]++;

    startingPos[0] = 1;
    for (int i = 1; i < n; i++)
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

    for (int i = 1; i <= num; i++) {
        int pos = startingPos[s[i][1]]++;
        t[pos][0] = s[i][1];
        t[pos][1] = s[i][0];
        t[pos][2] = s[i][2];
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

    fastTranspose(s, t);
    cout << "\nFast Transpose:";
    display(t);

    return 0;
}

