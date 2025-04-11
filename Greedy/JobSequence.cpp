#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> jobs = {{201, 5}, {181, 3}, {191, 3}, {301, 2}, {121, 4}, {101, 2}}; // {profit, deadline}

    sort(jobs.rbegin(), jobs.rend()); // Sort descending by profit

    int max_d = 0;
    int total = 0;
    int count = 0;
    for (auto &j : jobs)
        max_d = max(max_d, j.second);

    vector<bool> slot(max_d);

    for (auto &j : jobs)
        for (int i = min(j.second, max_d) - 1; i >= 0; i--)
            if (!slot[i])
            {
                slot[i] = true, total += j.first, count++;
                break;
            }

    cout << "Jobs: " << count << "\nProfit: " << total;
}