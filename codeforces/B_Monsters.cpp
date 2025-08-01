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
#define PI 3.141592653589793238462 #define all(x)(x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using lld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;

struct compare {
    bool operator()(const pii& a, const pii& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    fastio();

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;

        vi arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vpii updated_arr(n);
        for (int i = 0; i < n; i++) {
            updated_arr[i] = {arr[i] % k, i + 1};
            if (arr[i] % k == 0) {
                updated_arr[i] = {k, i + 1};
            }
        }

        sort(updated_arr.begin(), updated_arr.end(), compare());

        for (int i = 0; i < n; i++) {
            cout << updated_arr[i].second << " ";
        }
        cout << nline;
    }
    return 0;
}