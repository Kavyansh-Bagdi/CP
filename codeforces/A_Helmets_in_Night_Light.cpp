#include <bits/stdc++.h>

#define ff first
#define ss second
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;

struct compare {
    bool operator()(const pii& a, const pii& b) {
        if (a.ff == b.ff)
            return a.ss > b.ss;
        return a.ff < b.ff;
    }
};

int main() {
    int testcase;
    cin >> testcase;
    int n;  // number of ppl
    int p;  // cost when chief share
    vpii arr;
    for (int test = 0; test < testcase; test++) {
        cin >> n >> p;
        arr.resize(n, {0, 0});

        for (int i = 0; i < n; i++) {
            cin >> arr[i].ss;  // no of ppl
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[i].ff;  // cost of share
        }

        sort(arr.begin(), arr.end(), compare());

        long long cost = p;
        int cnt = n - 1;
        int idx = 0;
        while (cnt > 0 && idx < n) {
            if (arr[idx].ff >= p)
                break;

            if (arr[idx].ss >= cnt) {
                cost += 1LL * arr[idx].ff * cnt;
                cnt = 0;
            } else {
                cost += 1LL * arr[idx].ff * arr[idx].ss;
                cnt -= arr[idx].ss;
            }
            idx++;
        }

        if (cnt > 0)
            cost += 1LL * p * cnt;

        cout << cost << "\n";
        arr.clear();
    }
    return 0;
}