#include <bits/stdc++.h>
using namespace std;

// Recursive function for MCM
int f(vector<int>& d, int i, int j) {
    // Base case: only one matrix
    if (i == j)
        return 0;

    int mini = INT_MAX;

    // Try all partitions
    for (int k = i; k < j; k++) {
        int cost = f(d, i, k) + f(d, k + 1, j) + d[i] * d[k + 1] * d[j + 1];
        mini = min(mini, cost);
    }

    return mini;
}

int main() {
    // Dimension array d[] of size n+1 for n matrices
    vector<int> d = {15, 5, 10, 20, 10, 35, 25}; // 6 matrices (d.size() = 7)

    int n = d.size() - 1; // number of matrices = 6

    cout << "The minimum number of operations is " << f(d, 0, n - 1) << endl;

    return 0;
}
