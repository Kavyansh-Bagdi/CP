# Dijkstra's Algorithm

- not applicable if negative weights are present

| Approach | Time Complexity    | Space Complexity |
| -------- | ------------------ | ---------------- |
| Queue    | `O(V * E)`         | `O(V + E)`       |
| Min Heap | `O((V + E) log V)` | `O(V + E)`       |
| Set      | `O((V + E) log V)` | `O(V + E)`       |

## Queue Implementation

```cpp
vector<int> dijkstra(int V, vector<vector<int>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```

## Priority Queue Implementation

```cpp
vector<int> dijkstra(int V, vector<vector<int>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
```

## Set Implementation

```cpp
vector<int> dijkstra(int V, vector<vector<int>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    set<pair<int, int>> s;
    s.insert({0, src});

    while (!s.empty()) {
        auto it = *s.begin();
        s.erase(s.begin());

        int u = it.second;

        for (auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }

    return dist;
}
```

# Bellman-Ford Algorithm

`Time Complexity: O(V * E)`
`Space Complexity: O(V)`

- Relax all edges V-1 times
- If we can still relax an edge, it indicates a negative weight cycle.

```cpp
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }


    for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                throw runtime_error("Graph contains negative weight cycle");
            }
        }
    return dist;
}
```

# Floyd-Warshall Algorithm

`Time Complexity: O(V^3)`
`Space Complexity: O(V^2)`

- All-pairs shortest path problem

```cpp
vector<vector<int>> floydWarshall(int V, vector<vector<int>>& edges) {
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        dist[u][v] = min(dist[u][v], weight);
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    return dist;
}
```
