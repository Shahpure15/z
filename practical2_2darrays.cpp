#include <iostream> 
using namespace std; 
 
#define MAX 100   // Maximum non-zero elements 
 
// Triplet representation: [row, col, value] 
struct SparseMatrix { 
    int data[MAX][3];  // stores (row, col, value) 
    int rows, cols, terms;  // matrix dimensions and number of non-zero elements 
}; 
 
// Function to read sparse matrix 
void readSparse(SparseMatrix &s) { 
    cout << "Enter rows, cols and number of non-zero elements: "; 
    cin >> s.rows >> s.cols >> s.terms; 
 
    cout << "Enter row, col and value for each non-zero element:\n"; 
    for (int i = 1; i <= s.terms; i++) { 
        cin >> s.data[i][0] >> s.data[i][1] >> s.data[i][2]; 
    } 
 
    // Header 
    s.data[0][0] = s.rows; 
    s.data[0][1] = s.cols; 
    s.data[0][2] = s.terms; 
} 
 
// Function to display sparse matrix 
void displaySparse(const SparseMatrix &s) { 
    cout << "Row Col Val\n"; 
    for (int i = 0; i <= s.terms; i++) { 
        cout << s.data[i][0] << " " << s.data[i][1] << " " << s.data[i][2] << endl; 
    } 
} 
 
// Simple Transpose 
SparseMatrix transpose(const SparseMatrix &s) { 
    SparseMatrix t; 
    t.rows = s.cols; 
    t.cols = s.rows; 
    t.terms = s.terms; 
 
    t.data[0][0] = t.rows; 
    t.data[0][1] = t.cols; 
    t.data[0][2] = t.terms; 
 
    int k = 1; 
    for (int col = 0; col < s.cols; col++) { 
        for (int i = 1; i <= s.terms; i++) { 
            if (s.data[i][1] == col) { 
                t.data[k][0] = s.data[i][1]; 
                t.data[k][1] = s.data[i][0]; 
                t.data[k][2] = s.data[i][2]; 
                k++; 
            } 
        } 
    } 
    return t; 
} 
 
// Fast Transpose 
SparseMatrix fastTranspose(const SparseMatrix &s) { 
    SparseMatrix t; 
    int rowTerms[MAX], startingPos[MAX]; 
 
    t.rows = s.cols; 
    t.cols = s.rows; 
    t.terms = s.terms; 
 
    t.data[0][0] = t.rows; 
    t.data[0][1] = t.cols; 
    t.data[0][2] = t.terms; 
 
    if (s.terms > 0) { 
        for (int i = 0; i < s.cols; i++) rowTerms[i] = 0; 
        for (int i = 1; i <= s.terms; i++) rowTerms[s.data[i][1]]++; 
 
        startingPos[0] = 1; 
        for (int i = 1; i < s.cols; i++) 
            startingPos[i] = startingPos[i-1] + rowTerms[i-1]; 
 
        for (int i = 1; i <= s.terms; i++) { 
            int col = s.data[i][1]; 
            int pos = startingPos[col]++; 
            t.data[pos][0] = s.data[i][1]; 
            t.data[pos][1] = s.data[i][0]; 
            t.data[pos][2] = s.data[i][2]; 
        } 
    } 
    return t; 
} 
 
// Add two sparse matrices 
SparseMatrix add(const SparseMatrix &a, const SparseMatrix &b) { 
    SparseMatrix sum; 
    if (a.rows != b.rows || a.cols != b.cols) { 
        cout << "Matrices cannot be added!\n"; 
        sum.terms = 0; 
        return sum; 
    } 
 
    sum.rows = a.rows; 
    sum.cols = a.cols; 
 
    int i = 1, j = 1, k = 1; 
    while (i <= a.terms && j <= b.terms) { 
        if (a.data[i][0] < b.data[j][0] ||  
            (a.data[i][0] == b.data[j][0] && a.data[i][1] < b.data[j][1])) { 
            sum.data[k][0] = a.data[i][0]; 
            sum.data[k][1] = a.data[i][1]; 
            sum.data[k][2] = a.data[i][2]; 
            i++; k++; 
        } else if (b.data[j][0] < a.data[i][0] ||  
                  (a.data[i][0] == b.data[j][0] && b.data[j][1] < a.data[i][1])) { 
            sum.data[k][0] = b.data[j][0]; 
            sum.data[k][1] = b.data[j][1]; 
            sum.data[k][2] = b.data[j][2]; 
            j++; k++; 
        } else { 
            sum.data[k][0] = a.data[i][0]; 
            sum.data[k][1] = a.data[i][1]; 
            sum.data[k][2] = a.data[i][2] + b.data[j][2]; 
            i++; j++; k++; 
        } 
    } 
 
    while (i <= a.terms) { 
        sum.data[k][0] = a.data[i][0]; 
        sum.data[k][1] = a.data[i][1]; 
        sum.data[k][2] = a.data[i][2]; 
        i++; k++; 
    } 
 
    while (j <= b.terms) { 
        sum.data[k][0] = b.data[j][0]; 
        sum.data[k][1] = b.data[j][1]; 
        sum.data[k][2] = b.data[j][2]; 
        j++; k++; 
    } 
 
    sum.terms = k-1; 
    sum.data[0][0] = sum.rows; 
    sum.data[0][1] = sum.cols; 
    sum.data[0][2] = sum.terms; 
 
    return sum; 
} 
 
// Multiply two sparse matrices 
SparseMatrix multiply(const SparseMatrix &a, const SparseMatrix &b) { 
    SparseMatrix prod; 
    if (a.cols != b.rows) { 
        cout << "Matrices cannot be multiplied!\n"; 
        prod.terms = 0; 
        return prod; 
    } 
 
    SparseMatrix bt = fastTranspose(b); 
    prod.rows = a.rows; 
    prod.cols = b.cols; 
    prod.terms = 0; 
 
    int k = 1; 
    for (int i = 1; i <= a.terms;) { 
        int row = a.data[i][0]; 
 
        for (int j = 1; j <= bt.terms;) { 
            int col = bt.data[j][0]; 
            int tempa = i, tempb = j, sum = 0; 
 
            while (tempa <= a.terms && a.data[tempa][0] == row &&  
                   tempb <= bt.terms && bt.data[tempb][0] == col) { 
                if (a.data[tempa][1] < bt.data[tempb][1]) tempa++; 
                else if (a.data[tempa][1] > bt.data[tempb][1]) tempb++; 
                else { 
                    sum += a.data[tempa][2] * bt.data[tempb][2]; 
                    tempa++; tempb++; 
                } 
            } 
 
            if (sum != 0) { 
                prod.data[k][0] = row; 
                prod.data[k][1] = col; 
                prod.data[k][2] = sum; 
                k++; 
            } 
 
            while (j <= bt.terms && bt.data[j][0] == col) j++; 
        } 
 
        while (i <= a.terms && a.data[i][0] == row) i++; 
    } 
 
    prod.terms = k-1; 
    prod.data[0][0] = prod.rows; 
    prod.data[0][1] = prod.cols; 
    prod.data[0][2] = prod.terms; 
 
    return prod; 
} 
 
int main() { 
    SparseMatrix a, b; 
    cout << "Enter first matrix:\n"; 
    readSparse(a); 
    cout << "Enter second matrix:\n"; 
    readSparse(b); 
 
    cout << "\nMatrix A (Triplet form):\n"; 
    displaySparse(a); 
    cout << "\nMatrix B (Triplet form):\n"; 
    displaySparse(b); 
 
    cout << "\nTranspose of A:\n"; 
    displaySparse(transpose(a)); 
 
    cout << "\nFast Transpose of A:\n"; 
    displaySparse(fastTranspose(a)); 
 
    cout << "\nA + B:\n"; 
    displaySparse(add(a, b)); 
 
    cout << "\nA * B:\n"; 
    displaySparse(multiply(a, b)); 
 
    return 0; 
}
