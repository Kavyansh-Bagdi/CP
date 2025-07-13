#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define INF LLONG_MAX
#define MOD 1000000007
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

// int solve(int idx, int prev, int& n, int& m, vi& arr) {
//     if (idx == n) {
//         return 1;
//     }

//     if (arr[idx] != 0) {
//         if (idx == 0)
//             return solve(idx + 1, arr[idx], n, m, arr);

//         if (abs(prev - arr[idx]) <= 1)
//             return solve(idx + 1, arr[idx], n, m, arr);
//         else
//             return 0;
//     }

//     int cnt = 0;

//     if (idx == 0) {
//         for (int i = 1; i <= m; i++) {
//             cnt += solve(idx + 1, i, n, m, arr);
//         }
//     } else {
//         for (int i = prev - 1; i <= prev + 1; i++) {
//             if (i >= 1 && i <= m) {
//                 cnt += solve(idx + 1, i, n, m, arr);
//             }
//         }
//     }

//     return cnt;
// }

int main() {
    fastio();
    int n, m;
    cin >> n >> m;
    vi arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vvi dp(n + 1, vi(m + 1, 0));

    // basecase
    for (int i = 0; i <= m; i++)
        dp[n][i] = 1;

    for (int idx = n - 1; idx > -1; idx--) {
        for (int prev = 0; prev <= m; prev++) {
            if (arr[idx] != 0) {
                if (abs(prev - arr[idx]) <= 1 || prev == 0)
                    dp[idx][prev] = dp[idx + 1][arr[idx]];
                else
                    dp[idx][prev] = 0;
            } else {
                if (idx == 0) {
                    for (int i = 1; i <= m; i++) {
                        dp[idx][prev] = (dp[idx][prev] + dp[idx + 1][i]) % MOD;
                    }
                } else {
                    for (int i = prev - 1; i <= prev + 1; i++) {
                        if (i >= 1 && i <= m) {
                            dp[idx][prev] = (dp[idx][prev] + dp[idx + 1][i]) % MOD;
                        }
                    }
                }
            }
        }
    }

    cout << dp[0][0] << nline;
    return 0;
}