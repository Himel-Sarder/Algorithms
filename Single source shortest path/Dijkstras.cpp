#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> dijkstra(int V, int source, vector<vector<vector<int>>> &adj)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> Explored(V, false);

    dist[source] = 0;
    int count = V;

    while (count--)
    {
        int node = -1, value = INT_MAX;

        // Pick the unvisited node with the smallest distance
        for (int i = 0; i < V; i++)
        {
            if (!Explored[i] && dist[i] < value)
            {
                node = i;
                value = dist[i];
            }
        }

        if (node == -1)
            break; // No reachable node left

        Explored[node] = true;

        // Relax edges of the current node
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];

            if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[node] + weight;
            }
        }
    }

    return dist;
}

int main()
{
    int V = 4;
    int source = 0;

    // Adjacency list: adj[u] = {{v1, w1}, {v2, w2}, ...}
    vector<vector<vector<int>>> adj(V);

    // Graph edges
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 4});
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({0, 4});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 1});
    adj[3].push_back({1, 5});
    adj[3].push_back({2, 1});

    vector<int> result = dijkstra(V, source, adj);

    cout << "Final distance array from source " << source << ":\n[ ";
    for (int d : result)
        cout << d << " ";
    cout << "]\n";

    return 0;
}
