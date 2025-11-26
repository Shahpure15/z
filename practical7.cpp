#include <iostream>
using namespace std;

#define N 2  // 2x2 Sudoku grid

// Print Sudoku grid
void display(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

// Check if placing num at (r,c) is safe
bool isValid(int grid[N][N], int r, int c, int num) {
    for (int k = 0; k < N; k++) {
        if (grid[r][k] == num || grid[k][c] == num)
            return false;
    }
    return true;
}

// Recursive Backtracking Sudoku Solver
bool solve(int grid[N][N]) {
    int r = -1, c = -1;
    bool empty = false;

    // find empty cell
    for (int i = 0; i < N && !empty; i++) {
        for (int j = 0; j < N && !empty; j++) {
            if (grid[i][j] == 0) {
                r = i; c = j;
                empty = true;
            }
        }
    }

    if (!empty) return true; // solved

    for (int num = 1; num <= N; num++) {
        if (isValid(grid, r, c, num)) {
            grid[r][c] = num;

            if (solve(grid))
                return true;

            grid[r][c] = 0; // backtrack
        }
    }
    return false; // no number works
}

int main() {
    int grid[N][N];

    cout << "Enter 2x2 Sudoku (use 0 for empty cells):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    cout << "\nSolving Sudoku...\n";

    if (solve(grid)) {
        cout << "\nSolved Sudoku:\n";
        display(grid);
    } else {
        cout << "\nNo valid solution exists!\n";
    }
    return 0;
}
