#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    int n, num;
    cin >> n >> num;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(num + 1, 0);
    dp[0] = 1;

    for (int coin : arr) {
        for (int k = coin; k <= num; k++) {
            dp[k] = (dp[k] + dp[k - coin]) % MOD;
        }
    }

    cout << dp[num] << "\n";
    return 0;
}
