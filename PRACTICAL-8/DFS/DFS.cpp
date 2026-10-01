#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;

    cout << node << " ";

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            DFS(neighbour, adj, visited);
        }
    }
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges:\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // Remove this for directed graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    DFS(start, adj, visited);

    return 0;
}