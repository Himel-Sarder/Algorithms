#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {4, 3, 6, 5}, w = {3, 2, 5, 4}; // values, weights
    int c = 5, dp[51]{};                            // capacity, DP array

    for (int i = 0; i < v.size(); i++)
        for (int j = c; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    cout << "Max Value: " << dp[c];
}
