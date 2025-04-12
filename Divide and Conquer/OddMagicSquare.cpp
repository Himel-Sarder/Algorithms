#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter odd size of magic square: ";
    cin >> n;

    vector<vector<int>> magic(n, vector<int>(n, 0));

    // Starting position (top row middle)
    int row = 0, col = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magic[row][col] = num;

        // Calculate next position (up-right diagonal)
        int next_row = (row - 1 + n) % n; // Wrap around top/bottom
        int next_col = (col + 1) % n;     // Wrap around left/right

        // If next cell is empty, move there. Otherwise, move down.
        if (magic[next_row][next_col] == 0) {
            row = next_row;
            col = next_col;
        } else {
            row = (row + 1) % n; // Move down (same column)
        }
    }

    // Print magic square
    cout << "\nMagic Square (Sum = " << n*(n*n+1)/2 << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magic[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
