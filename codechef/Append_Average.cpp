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

using ll = long long;

int main() {
    fastio();
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll a = INF, b = INF;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < a) {
                b = a;
                a = arr[i];
            } else if (arr[i] < b) {
                b = arr[i];
            }
        }

        ll sum = 0;

        if (a == b) {
            sum += k * a;
            sum += accumulate(all(arr), 0LL);
            cout << sum << nline;
            continue;
        }

        while (k--) {
            ll num = (a + b + 1) / 2;
            sum += num;

            if (num < a) {
                b = a;
                a = num;
            } else if (num < b) {
                b = num;
            } else {
                sum += (ll)k * num;
                break;
            }
        }
        sum += accumulate(all(arr), 0LL); 
        cout << sum << nline;

    }

    return 0;
}
