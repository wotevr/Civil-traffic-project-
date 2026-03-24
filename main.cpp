#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Function to print path
void printPath(int dest, vector<int>& parent) {
    if (dest == -1) return;
    printPath(parent[dest], parent);
    cout << dest << " ";
}

void dijkstra(int n, vector<pair<int,int>> graph[], int src, int dest) {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        for (auto [adjNode, weight] : graph[node]) {
            if (d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Output
    cout << "\nShortest Distance: " << dist[dest] << endl;
    cout << "Path: ";
    printPath(dest, parent);
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges:\n";
    cin >> n >> m;

    vector<pair<int,int>> graph[n];

    cout << "Enter edges (u v distance traffic):\n";
    for (int i = 0; i < m; i++) {
        int u, v, distance, traffic;
        cin >> u >> v >> distance >> traffic;

        // 🔥 Updated formula (traffic more important)
        int weight = distance + 2 * traffic;

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int src, dest;
    cout << "Enter source and destination:\n";
    cin >> src >> dest;

    dijkstra(n, graph, src, dest);

    return 0;
}
