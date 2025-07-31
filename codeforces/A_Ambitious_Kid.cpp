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
    int n;
    cin >> n;
    vi arr(n);
    int min_abs = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        min_abs = min(abs(arr[i]),min_abs);
    }

    cout << min_abs << nline;
    return 0;
}