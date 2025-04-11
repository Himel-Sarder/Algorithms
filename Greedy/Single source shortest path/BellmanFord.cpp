#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
    int from, to, weight;
};

int main()
{
    int n = 4; // Number of nodes
    vector<Edge> edges = {
        {0, 1, 4},  // Edge from 0 to 1 with weight 4
        {0, 2, 1},  // Edge from 0 to 2 with weight 1
        {2, 1, -2}, // Edge from 2 to 1 with weight -2
        {2, 3, 5},  // Edge from 2 to 3 with weight 5
        {1, 3, 1}   // Edge from 1 to 3 with weight 1
    };

    int start = 0;
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    // Main Bellman-Ford algorithm
    for (int i = 0; i < n - 1; ++i)
    {
        for (auto &e : edges)
        {
            if (dist[e.from] != INT_MAX && dist[e.to] > dist[e.from] + e.weight)
            {
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }

    // Check for negative cycles
    bool hasNegativeCycle = false;
    for (auto &e : edges)
    {
        if (dist[e.from] != INT_MAX && dist[e.to] > dist[e.from] + e.weight)
        {
            hasNegativeCycle = true;
            break;
        }
    }

    // Output results
    if (hasNegativeCycle)
    {
        cout << "Graph contains negative weight cycle!\n";
    }
    else
    {
        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < n; ++i)
        {
            if (dist[i] == INT_MAX)
                cout << i << ": INF\n";
            else
                cout << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}