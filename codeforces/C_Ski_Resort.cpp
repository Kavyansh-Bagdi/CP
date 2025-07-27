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
    for (int t = 0; t < T; t++) {
        int n, k, q;
        cin >> n >> k >> q;

        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long ans = 0;
        int idx = 0;
        while (idx < n) {
            if (arr[idx] > q)
                idx++;
            else {
                int j = idx;
                while (j < n && arr[j] <= q)
                    j++;

                if (j - idx >= k) {
                    ans += 1LL * (j - idx - k + 1) * (j - idx - k + 2) / 2;
                }

                idx = j;
            }
        }

        cout << ans << nline;
    }
    return 0;
}