#include <iostream>
using namespace std;

/* SIZE of Sudoku */
#define N 4

/* Function to print Sudoku grid */
void printGrid(int grid[N][N]) {
    cout << "\nSolved 2x2 Sudoku (4x4 Grid):\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

/* Check if placing num is valid */
bool isSafe(int grid[N][N], int row, int col, int num) {

    // Check row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num)
            return false;
    }

    // Check column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num)
            return false;
    }

    // Check 2x2 box
    int startRow = row - row % 2;
    int startCol = col - col % 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

/* Recursive Backtracking function */
bool solveSudoku(int grid[N][N], int row, int col) {

    // If all rows completed -> Sudoku solved
    if (row == N - 1 && col == N)
        return true;

    // Move to next row after end of column
    if (col == N)
        return solveSudoku(grid, row + 1, 0);

    // Skip already filled cells
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    // Try placing digits 1 to 4
    for (int num = 1; num <= 4; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num; // Place number

            // Recursive call for next cell
            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        grid[row][col] = 0; // Backtrack
    }

    return false;
}

int main() {

    /* 0 means empty cell */
    int grid[N][N] = {
        {1, 0, 0, 0},
        {0, 0, 2, 1},
        {0, 1, 0, 0},
        {0, 3, 0, 0}
    };

    cout << "Original 2x2 Sudoku (4x4 Grid):\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    // Solve Sudoku
    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        cout << "\nNo solution exists!";

    return 0;
}

