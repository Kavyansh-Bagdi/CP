#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define neg_inf INT_MIN
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


int main() {
    fastio();

    int n, money;
    cin >> n >> money;

    vpii books(n, {0, 0});  // {{price,pages}, ...}

    for (int i = 0; i < n; i++) {
        cin >> books[i].ff;
    }

    for (int i = 0; i < n; i++) {
        cin >> books[i].ss;
    }

    vi dp(money + 1, 0);  // number of pages i can buy with n money

    for (int i = 0; i < n; ++i) {
        for (int cash = money; cash >= books[i].ff; --cash) {
            dp[cash] = max(dp[cash], books[i].ss + dp[cash - books[i].ff]);
        }
    }

    cout << dp[money] << nline;
    return 0;
}