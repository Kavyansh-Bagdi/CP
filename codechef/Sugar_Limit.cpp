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

int fun(const vector<int>& A, const vector<int>& B, int L, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (B[i] <= L && A[i] >= 0) {
            sum += A[i];
        }
    }
    return sum - L;
}

int main() {
    fastio();
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);

        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        int high = *max_element(all(B));
        int ans = 0;

        for (int i = 0; i <= high; i++) {
            ans = max(ans, fun(A, B, i, n));
        }

        cout << ans << nline;
    }

    return 0;
}
