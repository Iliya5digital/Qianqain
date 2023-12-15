#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> graph;

int dijkstra(int n) {
    vector<int> dist(n + 1, numeric_limits<int>::max());
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (pii neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n];
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int minPathLength = dijkstra(n);
    cout << minPathLength << endl;

    return 0;
}
