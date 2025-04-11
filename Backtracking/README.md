## Complete Line-by-Line Explanation of N-Queens Algorithm

### 1. Main Function
```cpp
int n;
cout << "Enter the number of queens: ";
cin >> n;
```
- Gets board size (e.g., user enters 4)

```cpp
vector<vector<char>> board(n, vector<char>(n, 'X'));
```
Creates 4×4 board initialized with 'X':
```
X X X X
X X X X
X X X X
X X X X
```

```cpp
nqueen(board, 0);
```
- Starts the algorithm from row 0

### 2. nqueen() Function
```cpp
void nqueen(vector<vector<char>> &board, int row) {
    int n = board.size();
```
- Gets board size (n=4)

```cpp
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
```
- Base case: When all rows filled (row=4), print solution
- Example solution format:
```
X Q X X 
X X X Q 
Q X X X 
X X Q X 
```

```cpp
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
```
- Try each column in current row
- Check if position (row,col) is safe

### 3. isSafe() Function
```cpp
bool isSafe(vector<vector<char>> &board, int row, int col) {
    int n = board.size();
```
- Gets board size (n=4)

```cpp
    // Check column (upward)
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
```
- Checks if any queen exists above in same column
- Example: Checking (2,1):
```
Q X X X 
X X X X 
X ? X X 
X X X X
```
- Looks at (0,1) and (1,1)

```cpp
    // Check north-west diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
```
- Checks upper-left diagonal
- Example: Checking (2,2):
```
X X Q X 
X X X X 
X X ? X 
X X X X
```
- Looks at (1,1) and (0,0)

```cpp
    // Check north-east diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
```
- Checks upper-right diagonal
- Example: Checking (2,1):
```
X Q X X 
X X X X 
X ? X X 
X X X X
```
- Looks at (1,2) and (0,3)

```cpp
    return true;
}
```
- Position is safe if all checks pass

### Back to nqueen():
```cpp
            board[row][col] = 'Q';  // Place queen
```
- Example: Place at (0,0):
```
Q X X X
X X X X
X X X X
X X X X
```

```cpp
            nqueen(board, row + 1); // Recurse to next row
```
- Recursively try to place queens in next rows

```cpp
            board[row][col] = 'X';  // Backtrack
```
- Remove queen if no solution found down this path
- Example: Backtrack from invalid path:
```
Q X X X
X X Q X
X Q X X
X X X X  // Dead end
```
- Removes last placed queen and tries next position

## Full Execution Example (N=4)

1. First solution found:
```
Row 0: Place at (0,1)
Row 1: Place at (1,3)
Row 2: Place at (2,0) 
Row 3: Place at (3,2)

Final board:
X Q X X 
X X X Q 
Q X X X 
X X Q X 
```

2. Second solution found:
```
Row 0: Place at (0,2)
Row 1: Place at (1,0)
Row 2: Place at (2,3)
Row 3: Place at (3,1)

Final board:
X X Q X 
Q X X X 
X X X Q 
X Q X X 
```

## Key Insights

1. **Row-wise placement**: Queens are placed one per row from top to bottom
2. **Three safety checks**:
   - Vertical (column)
   - Diagonal up-left
   - Diagonal up-right
3. **Backtracking**: When stuck, algorithm undoes last placement and tries next option
4. **Recursion depth**: Each recursive call handles the next row

The algorithm systematically explores all possible configurations while efficiently eliminating invalid paths early through the safety checks.
