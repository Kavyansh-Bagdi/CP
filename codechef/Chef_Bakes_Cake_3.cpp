#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define nline "\n"
using vi = vector<int>;

int profit(int cakes, const vi& customers) {
    int total = 0;
    for (int c : customers) {
        total += 50 * min(c, cakes) - 30 * cakes;
    }
    return total;
}

int max_profit(const vi& customers) {
    int low = 0, high = 1000;  // safe upper bound
    while (high - low > 3) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (profit(mid1, customers) < profit(mid2, customers)) {
            low = mid1 + 1;
        } else {
            high = mid2 - 1;
        }
    }

    int best = INT_MIN;
    for (int i = low; i <= high; i++) {
        best = max(best, profit(i, customers));
    }
    return best;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi customers(n);
        for (int i = 0; i < n; i++) {
            cin >> customers[i];
        }
        cout << max_profit(customers) << nline;
    }
    return 0;
}
