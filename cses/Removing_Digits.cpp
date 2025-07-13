#include <bits/stdc++.h>

#define MOD 1000000007
#define inf INT_MAX
#define nline "\n"

using namespace std;

// // Recursive Solution
// int solve(int num) {
//     if (num == 0)
//         return 0;
//     int cnt = inf;
//     int temp = num;
//     while (temp > 0) {
//         int rem = temp % 10;
//         cnt = min(cnt, solve(num - rem)) + 1;
//         temp /= 10;
//     }
//     return cnt;
// }

int main() {
    int num;
    cin >> num;

    vector<int> dp(num + 1, inf);
    dp[0] = 0;

    for (int k = 1; k <= num; k++) {
        int temp = k;
        while (temp > 0) {
            int rem = temp % 10;
            if (rem != 0) {
                int res = dp[k - rem];
                if (res != inf) {
                    dp[k] = min(dp[k], res + 1);
                }
            }
            temp /= 10;
        }
    }
    cout << dp[num] << nline;
    return 0;
}