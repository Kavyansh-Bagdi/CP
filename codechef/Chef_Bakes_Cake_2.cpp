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
    int t;
    cin >> t;

    int n;
    vi a, b;

    for (int test = 0; test < t; test++) {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] - b[i] >= 0) {
                cost += (a[i] - b[i]);
            }
        }

        cout << cost << nline;

        a.clear();
        b.clear();
    }
    return 0;
}