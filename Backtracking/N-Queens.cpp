#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col);
void nqueen(vector<vector<char>> &board, int row);

int main()
{
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, 'X'));
    nqueen(board, 0);
    return 0;
}

void nqueen(vector<vector<char>> &board, int row)
{
    int n = board.size();
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';  // Place queen
            nqueen(board, row + 1); // Recurse to next row
            board[row][col] = 'X';  // Backtrack
        }
    }
}

bool isSafe(vector<vector<char>> &board, int row, int col)
{
    int n = board.size();

    // Check column (upward)
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check north-west diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check north-east diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}
