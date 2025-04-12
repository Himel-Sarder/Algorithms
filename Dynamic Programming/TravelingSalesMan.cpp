#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int n = dist.size();

    vector<int> cities;

    for (int i = 1; i < n; i++)
        cities.push_back(i);

    int min_cost = INT_MAX;

    vector<int> optimal_path; // To store the best permutation

    do
    {
        int current_cost = 0;
        int current_city = 0;

        for (int city : cities)
        {
            current_cost += dist[current_city][city];
            current_city = city;
        }
        current_cost += dist[current_city][0];

        // Update minimum and path
        if (current_cost < min_cost)
        {
            min_cost = current_cost;
            optimal_path = cities; // Store the best permutation
        }

    } while (next_permutation(cities.begin(), cities.end()));

    // Output results
    cout << "Minimum TSP cost: " << min_cost << endl;
    cout << "Optimal Path: 0";
    for (int city : optimal_path)
    {
        cout << " -> " << city;
    }
    cout << " -> 0" << endl;

    return 0;
}