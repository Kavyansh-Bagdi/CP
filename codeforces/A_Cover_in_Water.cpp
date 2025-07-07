#include <bits/stdc++.h>
using namespace std;

// Constants
const long long llM = LLONG_MAX;
const long long llm = LLONG_MIN;
const int iM = INT_MAX;
const int im = INT_MIN;
const double PIE = 3.141592653589793;
#define MOD 1000000007

// Number Aliases
using l = long;
using ll = long long;
using ull = unsigned long long;

// Pairs
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Vectors
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vb = vector<bool>;

using vpii = vector<pii>;
using vpll = vector<pll>;

using vvi = vector<vi>;
using vvpii = vector<vpii>;

// Maps & Sets
using si = set<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;

// Queues & Stacks
using qi = queue<int>;
using pqi = priority_queue<int>;
using pqi_min = priority_queue<int, vi, greater<int>>;

// Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define sz(x) (int)(x).size()

int solve(int n, string& filip) {
    int i = 0, j = 0;
    int cnt = 0;

    while (j < n) {
        if (filip[j] == '.') {
            i = j;
            while (j < n && filip[j] != '#')
                j++;

            if (j - i <= 2)
                cnt += (j - i);
            else
                return 2;
        }
        j++;
    }

    return cnt;
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int n;
        string filip;

        cin >> n;
        cin >> filip;

        cout << solve(n, filip) << '\n';
    }
    return 0;
}