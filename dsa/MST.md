# Minimum Spanning Tree (MST)

## Prim's Algorithm

`Time Complexity: O(E log V) inserting into heap + O(E log V) extracting from heap`
`Space Complexity: O(E) for the heap + O(V) for the visited array`

```cpp
vector<int> prims(int V, vector<vector<int>>& adj) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];

            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    return parent;
}
```

## Kruskal's Algorithm

`Time Complexity: O(E log E) for sorting + O(E log V) for union-find operations`  
`Space Complexity: O(E) for the edges + O(V) for the parent and rank arrays`

### Using Union by Rank

```cpp
int kruskalByRank(int V, vector<vector<int>>& edges) {
    // edges: {u, v, weight}
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    DisjointSetRank ds(V);
    int mst_weight = 0;
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (ds.find(u) != ds.find(v)) {
            ds.unionByRank(u, v);
            mst_weight += w;
            // Optionally store the edge in MST
        }
    }
    return mst_weight;
}
```

### Using Union by Size

```cpp
int kruskalBySize(int V, vector<vector<int>>& edges) {
    // edges: {u, v, weight}
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    DisjointSetSize ds(V);
    int mst_weight = 0;
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (ds.find(u) != ds.find(v)) {
            ds.unionBySize(u, v);
            mst_weight += w;
            // Optionally store the edge in MST
        }
    }
    return mst_weight;
}
```
