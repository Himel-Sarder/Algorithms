#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

int main() {
    // Matrix dimensions: matrices are A0 (d[0]xd[1]), A1 (d[1]xd[2]), etc.
    vector<int> d = {10, 20, 30, 40, 30}; // 4 matrices
    int n = d.size() - 1; // Number of matrices

    // DP table: m[i][j] = min multiplications for matrices A_i to A_j
    vector<vector<int>> m(n, vector<int>(n, 0));

    // Fill the table for chains of increasing length
    for (int len = 2; len <= n; len++) { // Chain length
        for (int i = 0; i <= n - len; i++) { // Start index
            int j = i + len - 1; // End index
            m[i][j] = INT_MAX;

            // Try all possible split points between i and j
            for (int k = i; k < j; k++) {
                // Cost = left subchain + right subchain + current multiplication cost
                int cost = m[i][k] + m[k+1][j] + d[i] * d[k+1] * d[j+1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum multiplications: " << m[0][n-1];
    return 0;
}
