#include <bits/stdc++.h>
using namespace std;

string getLCS(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();

    // Step 1: Build the DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Step 2: Backtrack to find the LCS string
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcs += text1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Since we built LCS from the end, reverse it
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    string lcs = getLCS(str1, str2);
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length: " << lcs.size() << endl;

    return 0;
}
