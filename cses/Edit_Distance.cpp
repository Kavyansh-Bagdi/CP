#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    fastio();
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vvi dp(n + 1, vi(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; 
            } else {
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],     
                                   dp[i][j - 1],     
                                   dp[i - 1][j - 1]  
                               });
            }
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}
