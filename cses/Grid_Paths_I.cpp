#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define inf LLONG_MAX
#define mod 1000000007
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
using vs = vector<string>;

// // Recursive Solution
// int solve(int x, int y, int n, vs& grid) {
//     if (x >= n || y >= n)
//         return 0;
//     if (grid[x][y] == '*')
//         return 0;
//     if (x == n - 1 && y == n - 1)
//         return 1;

//     int right, down;
//     right = solve(x, y + 1, n, grid);
//     down = solve(x + 1, y, n, grid);

//     return (right + down) % mod;
// }

int main() {
    fastio();

    int n;
    cin >> n;
    vs grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vi prev(n, 0), curr(n, 0);
    prev[n - 1] = (grid[n - 1][n - 1] == '.') ? 1 : 0;

    for (int x = n - 1; x >= 0; x--) {
        fill(curr.begin(), curr.end(), 0);
        for (int y = n - 1; y >= 0; y--) {
            if (grid[x][y] == '*')
                continue;
            if (x + 1 < n)
                curr[y] = (curr[y] + prev[y]) % mod;
            if (y + 1 < n)
                curr[y] = (curr[y] + curr[y + 1]) % mod;
            if (x == n - 1 && y == n - 1)
                curr[y] = 1;
        }
        prev = curr;
    }

    cout << prev[0] << nline;
    return 0;
}