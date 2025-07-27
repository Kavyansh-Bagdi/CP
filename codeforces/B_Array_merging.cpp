#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using ll = long long;
using vi = vector<int>;

int main() {
    fastio();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vi arr1(n), arr2(n);

        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];

        unordered_map<int, int> maxStreak1, maxStreak2;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && arr1[j] == arr1[i])
                j++;
            maxStreak1[arr1[i]] = max(maxStreak1[arr1[i]], j - i);
            i = j;
        }

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && arr2[j] == arr2[i])
                j++;
            maxStreak2[arr2[i]] = max(maxStreak2[arr2[i]], j - i);
            i = j;
        }

        int ans = 0;

        for (auto& [val, streak1] : maxStreak1) {
            int streak2 = maxStreak2.count(val) ? maxStreak2[val] : 0;
            ans = max(ans, streak1 + streak2);
        }
        for (auto& [val, streak2] : maxStreak2) {
            if (!maxStreak1.count(val)) {
                ans = max(ans, streak2);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
