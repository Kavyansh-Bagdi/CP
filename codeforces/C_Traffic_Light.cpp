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
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        // position of green lights
        vi green_light;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'g') {
                green_light.push_back(i);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                int temp = INT_MAX;
                for (auto num : green_light) {
                    temp = min(temp, (num - i + n) % n);
                }
                ans = max(temp, ans);
            }
        }

        cout << ans << nline;
    }
    return 0;
}