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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<vector<int>> vvi;
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

    vvi arr = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
               {1, 2, 3, 3, 3, 3, 3, 3, 2, 1}, {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
               {1, 2, 3, 4, 5, 5, 4, 3, 2, 1}, {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
               {1, 2, 3, 4, 4, 4, 4, 3, 2, 1}, {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
               {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    string line;
    for (int test = 0; test < testCase; test++) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            cin >> line;
            for (int j = 0; j < 10; j++) {
                if (line[j] == 'X') {
                    sum += arr[i][j];
                }
            }
            line.clear();
        }
        cout << sum << nline;
    }
    return 0;
}