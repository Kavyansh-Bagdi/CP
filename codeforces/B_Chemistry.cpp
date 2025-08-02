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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        unordered_map<char, int> hash;
        for (char c : s) {
            hash[c]++;
        }
        int odd_cnt = 0;
        for (pair<char, int> p : hash) {
            if (p.ss % 2 == 1)
                odd_cnt++;
        }
        if (odd_cnt > k + 1) {
            cout << "NO" << nline;
        }else{
            cout << "YES" << nline;
        }
    }
    return 0;
}