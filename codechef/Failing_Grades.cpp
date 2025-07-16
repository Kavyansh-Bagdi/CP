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
    int no_testcase;
    cin >> no_testcase;

    for (int i = 0; i < no_testcase; i++) {
        int n;
        cin >> n;

        vi marks(n);
        for (int j = 0; j < n; j++) {
            cin >> marks[j];
        }

        float total = 0;
        float total_marks = 0;
        bool flag = true;

        for (int test = 0; test < n; test++) {
            total += 100;
            total_marks += marks[test];

            if ((total_marks / total )* 100.0 < 40.0) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Yes" << nline;
        else
            cout << "No" << nline;
    }
    return 0;
}