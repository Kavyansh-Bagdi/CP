# Topological Sort

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.

- don't work for cyclic graphs
- don't for undirected graphs
  Implementation

**DFS**
`Time Complexity: O(V + E)`
`Space Complexity: O(V)`

```cpp
void helper(int v, vector<bool> &visited, stack<int> &Stack, vector<vector<int>> &adj) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            helper(i, visited, Stack, adj);
        }
    }
    Stack.push(v);
}
vector<int> topologicalSort(int V, vector<vector<int>> &adj) {
    stack<int> Stack;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            helper(i, visited, Stack, adj);
        }
    }
    vector<int> result;
    while (!Stack.empty()) {
        result.push_back(Stack.top());
        Stack.pop();
    }

    return result;
}
```

**BFS or Kahn's Algorithm**
`Time Complexity: O(V + E)`
`Space Complexity: O(V)`

- First find **InDegree** or **Outdegree** of all vertices.
- Then push all vertices with indegree 0 into a queue.
- Then pop from the queue and reduce indegree of all its neighbours by 1.
- If any neighbour's indegree becomes 0, push it into the queue.

```cpp
vector<int> topologicalSort(int V, vector<vector<int> >& edges)
{
    vector<vector<int>> adj = constructadj(V,edges);

    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    if (result.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }

    return result;
}
```
