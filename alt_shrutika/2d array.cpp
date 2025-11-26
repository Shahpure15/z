#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Input dimensions of first matrix
    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;
    int A[r1][c1];

    cout << "Enter elements of Matrix A:\n";
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
            cin >> A[i][j];

    // Input dimensions of second matrix
    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;
    int B[r2][c2];

    cout << "Enter elements of Matrix B:\n";
    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
            cin >> B[i][j];

    // Addition 
    if(r1 != r2 || c1 != c2)
        cout << "Addition not possible (matrix sizes differ)\n";
    else {
        int sum[r1][c1];
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                sum[i][j] = A[i][j] + B[i][j];

        cout << "\nSum of A and B:\n";
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++)
                cout << sum[i][j] << " ";
            cout << endl;
        }
    }

    //  Multiplication 
    if(c1 != r2)
        cout << "Multiplication not possible (A's columns != B's rows)\n";
    else {
        int prod[r1][c2] = {0}; // initialize result matrix with 0
        for(int i=0;i<r1;i++)
            for(int j=0;j<c2;j++)
                for(int k=0;k<c1;k++)
                    prod[i][j] += A[i][k] * B[k][j];

        cout << "\nProduct of A and B:\n";
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++)
                cout << prod[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}

