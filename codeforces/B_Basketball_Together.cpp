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
    int n;
    ll d;
    cin >> n >> d;
    vi power(n);
    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    sort(power.begin(), power.end());

    int cnt = 0;
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        ll strongest = power[right];

        ll need = d / strongest + 1;

        if (right - left + 1 >= need) {
            cnt++;
            left += (need - 1);
            right--;
        } else {
            break;
        }
    }

    cout << cnt << "\n";
    return 0;
}
