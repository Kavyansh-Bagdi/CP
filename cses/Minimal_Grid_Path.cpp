#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define INF LLONG_MAX
#define nline "\n"
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using lld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;

int main() {
    fastio();
    int n;
    cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<string> next(n);

    next[n - 1] = string(1, grid[n - 1][n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        next[i] = string(1, grid[n - 1][i]) + next[i + 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        next[n - 1] = grid[i][n - 1] + next[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            string down = grid[i][j] + next[j];
            string right = grid[i][j] + next[j + 1];
            next[j] = min(down, right);
        }
    }

    cout << next[0] << nline;
    return 0;
}