#include <iostream>
#include <vector>
using namespace std;

// Generate odd-sized magic square using Siamese method
vector<vector<int>> generateOddMagic(int m) {
    vector<vector<int>> magic(m, vector<int>(m, 0));
    int row = 0, col = m / 2;
    
    for (int num = 1; num <= m*m; num++) {
        magic[row][col] = num;
        int next_row = (row - 1 + m) % m;
        int next_col = (col + 1) % m;
        
        if (magic[next_row][next_col] == 0) {
            row = next_row;
            col = next_col;
        } else {
            row = (row + 1) % m;
        }
    }
    return magic;
}

// Create singly even magic square (n = 4k + 2)
vector<vector<int>> createSinglyEven(int n) {
    int m = n / 2;
    int k = (m - 1) / 2;  // Calculate swap range
    
    // 1. Generate base odd magic square
    auto base = generateOddMagic(m);
    
    // 2. Create four quadrants
    vector<vector<int>> A(m, vector<int>(m));
    vector<vector<int>> B(m, vector<int>(m));
    vector<vector<int>> C(m, vector<int>(m));
    vector<vector<int>> D(m, vector<int>(m));
    
    int mSq = m * m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = base[i][j];          // 1st quadrant (1 to m²)
            B[i][j] = base[i][j] + mSq;    // 2nd quadrant (m²+1 to 2m²)
            C[i][j] = base[i][j] + 2*mSq;  // 3rd quadrant (2m²+1 to 3m²)
            D[i][j] = base[i][j] + 3*mSq;  // 4th quadrant (3m²+1 to 4m²)
        }
    }
    
    // 3. Swap columns between quadrants
    for (int i = 0; i < m; i++) {
        // Swap first k columns of A and D
        for (int j = 0; j < k; j++) {
            swap(A[i][j], D[i][j]);
        }
        
        // Swap last (k-1) columns of B and C
        for (int j = m - k + 1; j < m; j++) {
            swap(B[i][j], C[i][j]);
        }
    }
    
    // 4. Combine into final magic square
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // Top-left quadrant (A)
            result[i][j] = A[i][j];
            // Top-right quadrant (B)
            result[i][j + m] = B[i][j];
            // Bottom-left quadrant (C)
            result[i + m][j] = C[i][j];
            // Bottom-right quadrant (D)
            result[i + m][j + m] = D[i][j];
        }
    }
    return result;
}

// Print magic square with sum verification
void printMagic(const vector<vector<int>>& magic) {
    int n = magic.size();
    int sum = n * (n*n + 1) / 2;
    
    cout << "Magic Square (Sum = " << sum << "):\n";
    for (const auto& row : magic) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter singly even size (n = 4k + 2): ";
    cin >> n;
    
    if (n % 2 != 0 || n % 4 == 0) {
        cout << "Invalid input! Must be singly even (6, 10, 14...)\n";
        return 1;
    }
    
    auto magic = createSinglyEven(n);
    printMagic(magic);
    
    return 0;
}
