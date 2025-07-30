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
        int n;
        cin >> n;
        string s;
        cin >> s;

        vi prefix_unique(n + 1, 0);
        vector<bool> seen(26, false);

        for (int i = 0; i < n; i++) {
            prefix_unique[i + 1] = prefix_unique[i];
            if (!seen[s[i] - 'a']) {
                prefix_unique[i + 1]++;
                seen[s[i] - 'a'] = true;
            }
        }

        vi suffix_unique(n + 1, 0);
        fill(seen.begin(), seen.end(), false);

        for (int i = n - 1; i >= 0; i--) {
            suffix_unique[i] = suffix_unique[i + 1];
            if (!seen[s[i] - 'a']) {
                suffix_unique[i]++;
                seen[s[i] - 'a'] = true;
            }
        }

        int ans = 0;

        for (int i = 0; i <= n; i++) {
            ans = max(ans, prefix_unique[i] + suffix_unique[i]);
        }

        cout << ans << nline;
    }
    return 0;
}