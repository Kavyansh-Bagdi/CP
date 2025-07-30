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

int main() {
    fastio();
    int T;
    cin >> T;

    while (T--) {
        ll n;
        cin >> n;

        ll a = 1, b = n - 1;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a = n / i;
                b = n - a;
                break;
            }
        }

        cout << a << " " << b << nline;
    }
    return 0;
}