#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= k; num++) {
        for (int coin : arr) {
            if (num >= coin) {
                dp[num] = (dp[num] + dp[num - coin]) % MOD;
            }
        }
    }
    cout << dp[k] % MOD << "\n";
    return 0;
}