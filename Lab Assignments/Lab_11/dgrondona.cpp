#include <iostream>
#include <vector>

using namespace std;

// edge struct
struct Edge {
    int to;
    int weight;
};

int main() {
    int V, E;
    std::cin >> V;
    std::cin >> E;

    // adjacency list
    std::vector<std::vector<Edge>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // large number
    int INF = 1000000;

    std::vector<int> key(V, INF);
    std::vector<int> parent(V, -1);
    std::vector<bool> inMST(V, false);

    // root = 0
    key[0] = 0;

    // Prim's algorithm
    for (int count = 0; count < V; count++) {

        // find vertex with minimum key not in MST
        int u = -1;
        int minKey = INF;

        for (int i = 0; i < V; i++) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        // include u in MST
        inMST[u] = true;

        // update adjacent vertices
        for (int i = 0; i < adj[u].size(); i++) {

            int v = adj[u][i].to;
            int weight = adj[u][i].weight;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // output parents for vertices 1..V-1
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << endl;
    }

    return 0;
}