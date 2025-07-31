#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ff first
#define ss second

using pii = pair<long long, long long>;
using vpii = vector<pii>;

int main() {
    fastio();
    int T;
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a >> b;
        pii king, queen;
        cin >> king.ff >> king.ss;
        cin >> queen.ff >> queen.ss;

        vpii diff = {{a, b}, {a, -b}, {-a, b}, {-a, -b},
                     {b, a}, {b, -a}, {-b, a}, {-b, -a}};

        set<pii> king_candidates, queen_candidates;

        for (auto d : diff) {
            king_candidates.insert({king.ff - d.ff, king.ss - d.ss});
            queen_candidates.insert({queen.ff - d.ff, queen.ss - d.ss});
        }

        int ans = 0;
        for (auto& pos : king_candidates) {
            if (queen_candidates.count(pos))
                ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
