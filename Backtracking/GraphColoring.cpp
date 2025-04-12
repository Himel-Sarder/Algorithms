#include <iostream>
using namespace std;

const int V = 4; // Number of vertices in the graph

// Graph representation (adjacency matrix)
int graph[V][V] = {
    {0, 1, 1, 1}, // Connections for node 0
    {1, 0, 1, 0}, // Connections for node 1
    {1, 1, 0, 1}, // Connections for node 2
    {1, 0, 1, 0}  // Connections for node 3
};

int m = 3;    // Number of colors available
int color[V]; // Array to store colors of vertices

// Check if current color assignment is safe
bool isSafe(int v, int c)
{
    // Check all adjacent vertices
    for (int i = 0; i < V; i++)
    {
        // If adjacent vertex has same color, return false
        if (graph[v][i] && color[i] == c)
        {
            return false;
        }
    }
    return true;
}

// Recursive backtracking function
void graphColoring(int v)
{
    // Base case: all vertices colored
    if (v == V)
    {
        // Print solution
        cout << "Solution found: ";
        for (int i = 0; i < V; i++)
        {
            cout << color[i] << " ";
        }
        cout << "\n";
        return;
    }

    // Try all colors for current vertex
    for (int c = 1; c <= m; c++)
    {
        // Check if color is valid
        if (isSafe(v, c))
        {
            color[v] = c; // Assign color

            // Recur for next vertex
            graphColoring(v + 1);

            // Backtrack (remove color)
            color[v] = 0;
        }
    }
}

int main()
{
    // Initialize color array
    for (int i = 0; i < V; i++)
    {
        color[i] = 0;
    }

    cout << "All possible colorings with " << m << " colors:\n";
    graphColoring(0); // Start with first vertex

    return 0;
}
