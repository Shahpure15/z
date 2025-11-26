#include <iostream>
using namespace std;

void display(int s[][3]) {
    cout << "\nRow\tCol\tVal\n";
    for (int i = 0; i <= s[0][2]; i++)
        cout << s[i][0] << "\t" << s[i][1] << "\t" << s[i][2] << endl;
}

// Sparse Addition
void addSparse(int a[][3], int b[][3], int c[][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "\nMatrices cannot be added!";
        return;
    }

    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        } else if (a[i][0] < b[j][0] ||
                  (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        } else {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
    }

    while (i <= a[0][2]) c[k][0] = a[i][0], c[k][1] = a[i][1], c[k][2] = a[i][2], i++, k++;
    while (j <= b[0][2]) c[k][0] = b[j][0], c[k][1] = b[j][1], c[k][2] = b[j][2], j++, k++;

    c[0][2] = k - 1;
}

// Sparse Multiplication
void multiplySparse(int a[][3], int b[][3], int c[][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "\nCannot multiply!";
        return;
    }

    int k = 1;
    c[0][0] = a[0][0];
    c[0][1] = b[0][1];

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                c[k][0] = a[i][0];
                c[k][1] = b[j][1];
                c[k][2] = a[i][2] * b[j][2];
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}

int main() {
    int a[20][3], b[20][3], c[40][3];

    int r1, c1, r2, c2;

    cout << "Enter rows & cols of matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows & cols of matrix B: ";
    cin >> r2 >> c2;

    int m1[10][10], m2[10][10];

    cout << "Enter Matrix A:\n";
    int nz1 = 0;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> m1[i][j];
            if (m1[i][j] != 0)
                nz1++;
        }
    }

    cout << "Enter Matrix B:\n";
    int nz2 = 0;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> m2[i][j];
            if (m2[i][j] != 0)
                nz2++;
        }
    }

    // Sparse A
    a[0][0] = r1; a[0][1] = c1; a[0][2] = nz1;
    int k = 1;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            if (m1[i][j] != 0)
                a[k][0] = i, a[k][1] = j, a[k][2] = m1[i][j], k++;

    // Sparse B
    b[0][0] = r2; b[0][1] = c2; b[0][2] = nz2;
    k = 1;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            if (m2[i][j] != 0)
                b[k][0] = i, b[k][1] = j, b[k][2] = m2[i][j], k++;

    cout << "\nSparse A:";
    display(a);
    cout << "\nSparse B:";
    display(b);

    cout << "\nAddition:";
    addSparse(a, b, c);
    display(c);

    cout << "\nMultiplication:";
    multiplySparse(a, b, c);
    display(c);

    return 0;
}

