#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void prims(vector<vector<int>>& graph, int n)
{
    
    vector<bool> visited(n, false);

   
    visited[0] = true;

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int count = 0; count < n - 1; count++)
    {
        int minimum = INT_MAX;
        int u = -1;
        int v = -1;

       
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < minimum)
                    {
                        minimum = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        
        cout << u << " - " << v
             << "  Cost = " << minimum << endl;

        totalCost += minimum;

        visited[v] = true;
    }

    cout << "\nTotal Cost of MST = " << totalCost << endl;
}

int main()
{
    int n;


    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));


    cout << "\nEnter the adjacency matrix:\n";
    cout << "(Enter 0 if there is no edge)\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    prims(graph, n);

    return 0;
}