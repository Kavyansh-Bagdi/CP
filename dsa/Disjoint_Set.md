# Disjoint Set

`α(n) ≤ 4 for n < 2^(65536)`

| Operation     | Without Optimizations | With Path Compression + Union by Rank |
| ------------- | --------------------- | ------------------------------------- |
| `find(x)`     | `O(n)`                | `O(α(n))` amortized                   |
| `union(x, y)` | `O(n)`                | `O(α(n))` amortized                   |

## Rank

```cpp
class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            return find(parent[x]);
            // Uncomment the next line for path compression
            // parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
```

## Size

```cpp
class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            return find(parent[x]);
            // Uncomment the next line for path compression
            // parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    void unionBySize(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }
    int getSize(int x) {
        return size[find(x)];
};
```
