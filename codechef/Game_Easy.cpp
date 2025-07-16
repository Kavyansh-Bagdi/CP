#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MIN;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> A[i];

        vector<vector<vector<int>>> dp(
            N + 1, vector<vector<int>>(2 * N + 1, vector<int>(N + 1, INF)));
        dp[0][0][0] = 0;

        for (int i = 0; i < N; ++i) {
            for (int k = 0; k <= 2 * N; ++k) {
                for (int x = 0; x <= i; ++x) {
                    if (dp[i][k][x] == INF)
                        continue;

                    dp[i + 1][k][x] = max(dp[i + 1][k][x], dp[i][k][x]);
                    if (k + 1 <= 2 * N)
                        dp[i + 1][k + 1][x + 1] = max(dp[i + 1][k + 1][x + 1],
                                                      dp[i][k][x] + A[i + 1]);
                    if (k + 2 <= 2 * N)
                        dp[i + 1][k + 2][x + 1] =
                            max(dp[i + 1][k + 2][x + 1],
                                dp[i][k][x] + A[i + 1] + x);
                }
            }
        }

        for (int k = 1; k <= 2 * N; ++k) {
            int ans = INF;
            for (int x = 0; x <= N; ++x)
                ans = max(ans, dp[N][k][x]);
            cout << ans << " ";
        }
        cout << "\n";
    }

    return 0;
}
