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

bool is_happy(vector<int>& arr,int c){
    if(arr[0] >= c) return false;
    return !binary_search(arr.begin(),arr.end(),c);
}
int main() {
    fastio();
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, c;
        cin >> n >> c;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(all(arr));

        int ans = 0;
        while(!is_happy(arr,c+ans)){
            ans++;
        }
        
        cout << ans << nline;
    }
    return 0;
}