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
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vi ans;
        ans.push_back(arr[0]);
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                ans.push_back(arr[i]);
                cnt++;
            }
            ans.push_back(arr[i]);
        }

        cout << cnt + n << nline;
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << nline;
    }
    return 0;
}