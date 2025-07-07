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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vi coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<vector<int>> dp(n, vector<int>(target + 1, INT_MAX));

    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
    }

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int notTake = dp[i - 1][t];
            int take = INT_MAX;
            if (coins[i] <= t && dp[i][t - coins[i]] != INT_MAX)
                take = 1 + dp[i][t - coins[i]];
            dp[i][t] = min(take, notTake);
        }
    }

    int result = dp[n - 1][target];
    cout << (result == INT_MAX ? -1 : result);

    return 0;
}
