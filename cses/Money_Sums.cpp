#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using vi = vector<int>;

int main() {
    fastio();
    int n;
    cin >> n;

    vi coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int total_sum = accumulate(coins.begin(), coins.end(), 0);
    vector<bool> dp(total_sum + 1, false);
    dp[0] = true;

    for (int coin : coins) {
        vector<bool> next_dp = dp;
        for (int i = 0; i <= total_sum; i++) {
            if (dp[i]) {
                next_dp[i + coin] = true;
            }
        }
        dp = next_dp;
    }

    vector<int> result;
    for (int i = 1; i <= total_sum; i++) {
        if (dp[i])
            result.push_back(i);
    }

    cout << result.size() << "\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
