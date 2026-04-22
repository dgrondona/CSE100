#include <iostream>
#include <vector>

using namespace std;

// Very large number, practically infinity
const long long INF = 1e18;

// Edge stores u, v, and w
struct Edge {
    int u, v, w;
};

// Initialize Distances
void init(std::vector<long long>& dist, int V, int s) {

    dist.assign(V, INF);
    dist[s] = 0;

}

// Relax an edge
void relax(int u, int v, int w, vector<long long>& dist) {

    if (dist[u] != INF && dist[v] > dist[u] + w) {

        dist[v] = dist[u] + w;  

    }

}

bool bellmanFord(int V, vector<Edge>& edges, vector<long long>& dist, int s) {

    // Initialize Single Source
    init(dist, V, s);

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {

        for (int j = 0; j < edges.size(); j++) {

            relax(edges[j].u, edges[j].v, edges[j].w, dist);

        }

    }

    // Check for negative cycles
    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dist[u] != INF && dist[v] > dist[u] + w) {

            return false; // Negative cycle

        }

    }

    return true;

}

int main (int argc, char **argv) {

    int V, E;
    std::cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++) {

        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;

    }

    vector<long long> dist;

    if (!bellmanFord(V, edges, dist, 0)) {

        std::cout << "FALSE" << std::endl;

    } else {

        std::cout << "TRUE" << std::endl;

        for (int i = 0; i < V; i++) {

            if (dist[i] == INF) {

                std::cout << "INFINITY" << std::endl;

            } else {

                std::cout << dist[i] << std::endl;

            }

        }

    }

    return 0;

}