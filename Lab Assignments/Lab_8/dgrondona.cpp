#include <iostream>
#include <vector>

using namespace std;

// Fill order DFS
void dfs1 (int u, std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<int>& order) {

    visited[u] = true; // Mark current node as visited

    // Explore outgoing edges
    for (int i = 0; i < graph[u].size(); i++) {

        int v = graph[u][i];

        if (!visited[v]) {

            dfs1(v, graph, visited, order);

        }

    }

    // Stack push AFTER visiting neighbors
    order.push_back(u);

}

// Collect SCC
void dfs2 (int u, std::vector<std::vector<int>>& rGraph, std::vector<bool>& visited, std::vector<int>& component) {

    visited[u] = true; // Mark current node as visited

    component.push_back(u); // Add node to current SCC

    // Explore reversed edges u -> v
    for (int i = 0; i < rGraph[u].size(); i++) {

        int v = rGraph[u][i];

        if (!visited[v]) {

            dfs2(v, rGraph, visited, component);

        }

    }

}


int main (int argc, char **argv) {

    int V, E;
    std::cin >> V >> E;

    // Adjacency list for og graph
    std::vector<std::vector<int>> graph(V);

    // Adjacency list for reversed graph
    std::vector<std::vector<int>> rGraph(V);

    // Read edges
    for (int i = 0; i < E; i++) {

        int u, v;
        std::cin >> u >> v;

        graph[u].push_back(v);
        rGraph[v].push_back(u); // Reverse edge

    }

    // Track visited nodes
    std::vector<bool> visited(V, false);

    // Store nodes in order of finishing time
    std::vector<int> order;

    // DFS on og graph to get finish order
    for (int i = 0; i < V; i++) {

        if (!visited[i]) {

            dfs1(i, graph, visited, order);

        }

    }

    // Reset graph for second DFS
    for (int i = 0; i < V; i++) {

        visited[i] = false;

    }

    // Stores final SCC ID for each vertex
    std::vector<int> sccID(V, -1);

    // Process in reverse order
    for (int i = order.size() - 1; i >= 0; i--) {

        int node = order[i];

        // If node is not yet assigned to an SCC
        if (!visited[node]) {

            std::vector<int> component;

            // Run DFS on reversed graph to find SCC
            dfs2(node, rGraph, visited, component);

            // Minimum
            int min = component[0];

            // Find smallest vertex in SCC
            for (int j = 1; j < component.size(); j++) {

                if (component[j] < min) {

                    min = component[j];

                }

            }

            // Assign SCC ID to all nodes in component
            for (int j = 0; j < component.size(); j++) {

                sccID[component[j]] = min;

            }

        }

    }

    // Output
    for (int i = 0; i < V; i++) {

        std::cout << sccID[i] << std::endl;

    }

    return 0;

}