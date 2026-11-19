#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u, v, weight;
};

bool compare(Edge a, Edge b){
    return a.weight < b.weight;
}

vector<int> parent;

int find(int x){
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    int px = find(x);
    int py = find(y);

    parent[px] = py;
}

void kruskal(int V, vector<Edge>& edges){
    sort(edges.begin(), edges.end(), compare);

    parent.resize(V);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;

    cout << "\nEdges in MST:\n";

    for (auto edge : edges){
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        if (find(u) != find(v)){
            cout << u << " - " << v << "  Cost = " << w << endl;

            totalCost += w;

            Union(u, v);
        }
    }

    cout << "\nTotal Cost = " << totalCost << endl;
}

int main(){
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter (u v weight):\n";

    for (int i = 0; i < E; i++){
        cin >> edges[i].u>> edges[i].v>> edges[i].weight;
    }

    kruskal(V, edges);

    return 0;
}