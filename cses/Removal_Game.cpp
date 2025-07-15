#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define nline "\n"

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

ll dp[5001][5001];

ll solve(int i, int j, const vi& arr) {
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int chance = (j - i + 1) % 2;

    if (chance == 0) {
        return dp[i][j] = max(arr[i] + solve(i + 1, j, arr),
                              arr[j] + solve(i, j - 1, arr));
    } else {
        return dp[i][j] = min(solve(i + 1, j, arr), solve(i, j - 1, arr));
    }
}

int main() {
    fastio();
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, n - 1, arr) << nline;
    return 0;
}
