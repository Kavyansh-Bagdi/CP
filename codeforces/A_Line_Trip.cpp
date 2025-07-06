#include <bits/stdc++.h>
using namespace std;

//  Constants
const long long llM = LLONG_MAX;
const long long llm = LLONG_MIN;
const int iM = INT_MAX;
const int im = INT_MIN;
const double PIE = 3.141592653589793;
#define MOD 1000000007

//  Number Aliases
using l = long;
using ll = long long;
using ull = unsigned long long;

//  Pairs
using pii = pair<int, int>;
using pll = pair<ll, ll>;

//  Vectors
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vb = vector<bool>;

using vpii = vector<pii>;
using vpll = vector<pll>;

using vvi = vector<vi>;
using vvpii = vector<vpii>;

//  Maps & Sets
using si = set<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;

//  Queues & Stacks
using qi = queue<int>;
using pqi = priority_queue<int>;
using pqi_min = priority_queue<int, vi, greater<int>>;

//  Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define each(x, a) for (auto &x : a)
#define sz(x) (int)(x).size()

bool reach(int fuelTank, vb &stations)
{
    int fuel = fuelTank;
    for (int i = 1; i < sz(stations); i++)
    {
        if (fuel == 0)
            return false;
        fuel--;
        if (stations[i])
            fuel = fuelTank;
    }
    return true;
}

int solve(vb &stations)
{
    int dist = sz(stations);
    int low = 1, high = dist;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        bool canReach = reach(mid, stations);
        if (canReach)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, x;
        cin >> s;
        cin >> x;
        vb stations(x * 2 + 1, false);

        for (int i = 0; i < s; i++)
        {
            int idx;
            cin >> idx;
            stations[idx] = true;
            stations[2 * x - idx] = true;
        }

        cout << solve(stations) << '\n';
    }
    return 0;
}