#include <iostream>
using namespace std;

#define INF (int)(1e9) // Represents infinity (no direct path)
#define V 4            // Number of vertices

void floydWarshall(int graph[V][V])
{
    int dist[V][V]; // Distance matrix

    // Initialize distance matrix with input graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // Update shortest path through vertex k
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Example graph (4x4 adjacency matrix)
    int graph[V][V] = {{0, INF, 2, 4},   // 0 -> 0, 0->1, 0->2, 0->3
                       {3, 0, INF, 10},  // 1 -> 0, 1->1, 1->2, 1->3
                       {INF, INF, 0, 1}, // 2 -> 0, 2->1, 2->2, 2->3
                       {6, 4, INF, 0}};  // 3 -> 0, 3->1, 3->2, 3->3

    floydWarshall(graph);
    return 0;
}
