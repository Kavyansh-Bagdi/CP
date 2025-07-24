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

const long long mod = 1e9 + 7;
ll power(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}

int main() {
    fastio();
    ll n;
    cin >> n;
    ll ans = (power(3, 3LL * n) - power(7, n) + mod) % mod;
    cout << ans << nline;
    return 0;
}