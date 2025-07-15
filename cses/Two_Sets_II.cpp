#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 1000000007
using ll = long long;

int main() {
    fastio();
    int n;
    cin >> n;

    ll total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    int target = total / 2;

    vector<ll> dp(target + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; ++num) {
        for (int j = target; j >= num; --j) {
            dp[j] = (dp[j] + dp[j - num]) % mod;
        }
    }

    ll inv2 = 500000004; 
    cout << (dp[target] * inv2) % mod << "\n";

    return 0;
}
