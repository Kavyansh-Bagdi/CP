#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define leadingz __builtin_clz
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define iM INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {
    cerr << t;
}
void _print(int t) {
    cerr << t;
}
void _print(string t) {
    cerr << t;
}
void _print(char t) {
    cerr << t;
}
void _print(lld t) {
    cerr << t;
}
void _print(double t) {
    cerr << t;
}
void _print(ull t) {
    cerr << t;
}

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int testCase;
    cin >> testCase;
    int n, k;
    vector<int> arr;
    for (int test = 0; test < testCase; test++) {
        cin >> n >> k;
        arr.resize(n);
        int ans = iM, even_cnt = 0, odd_cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even_cnt++;
            else
                odd_cnt++;
            if(arr[i] % k == 0) ans = 0;
            ans = min(ans,k - (arr[i]%k));
        }

        if(k == 4){
            if(even_cnt >= 2) ans = min(ans,0);
            else if( even_cnt == 1 && odd_cnt >= 1) ans = min(ans,1);
            else ans = min(ans,2);
        }

        cout<<ans<<"\n";
        arr.clear();
    }
    return 0;
}