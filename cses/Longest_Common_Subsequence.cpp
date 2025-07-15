#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define INF LLONG_MAX
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

int solve(int m, int n, vi& arr1, vi& arr2) {
    if (m < 0 || n < 0)
        return 0;

    if (arr1[m] == arr2[n]) {
        return 1 + solve(m - 1, n - 1, arr1, arr2);
    }

    return max(solve(m, n - 1, arr1, arr2), solve(m - 1, n, arr1, arr2));
}

int main() {
    fastio();
    int m, n;
    cin >> m >> n;

    vi arr1(m), arr2(n);

    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    vvi dp(m + 1, vi(n + 1, 0));

    for (int i1 = 1; i1 <= m; i1++) {
        for (int i2 = 1; i2 <= n; i2++) {
            if (arr1[i1 - 1] == arr2[i2 - 1]) {
                dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
            } else {
                dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
            }
        }
    }
    cout << dp[m][n] << nline;

    int i1 = m, i2 = n;
    stack<int> s;
    while(i1 > 0 && i2 > 0){
        if(arr1[i1-1] == arr2[i2-1]){
            s.push(arr1[i1-1]);
            i1--;
            i2--;
        }
        else if(dp[i1-1][i2] > dp[i1][i2-1]){
            i1--;
        }
        else{
            i2--;
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}