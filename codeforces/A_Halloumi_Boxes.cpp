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

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        bool isSorted = true;
        int preMax = -1;

        for (int j = 0; j < n; j++)
        {
            if (preMax > arr[j])
            {
                isSorted = false;
                break;
            }
            preMax = arr[j];
        }

        if (isSorted || k > 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}