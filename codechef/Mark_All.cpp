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
    int no_testcase;
    cin >> no_testcase;
    int n;
    vi arr;

    for (int test = 0; test < no_testcase; test++) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long cost = min(arr[0], arr[n - 1]);

        for (int idx = 2; idx < n - 2; idx++) {
            cost = min(cost, 1LL * (arr[idx] + arr[idx + 1]));
        }

        cout << cost << nline;

        arr.clear();
    }
    return 0;
}