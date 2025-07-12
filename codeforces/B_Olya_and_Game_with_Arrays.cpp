#include <bits/stdc++.h>

using namespace std;
#define inf INT_MAX
#define ff first
#define ss second
using pii = pair<int, int>;
using vpii = vector<pii>;

int main() {
    int no_testcase;
    cin >> no_testcase;
    vpii arr;
    for (int test = 0; test < no_testcase; test++) {
        int no_list;
        cin >> no_list;
        arr.resize(no_list, {inf, inf});

        for (int i = 0; i < no_list; i++) {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int num;
                cin >> num;

                if (num < arr[i].ff) {
                    arr[i].ss = arr[i].ff;
                    arr[i].ff = num;
                } else if (num < arr[i].ss)
                    arr[i].ss = num;
            }
        }

        int min_second_element = inf, min_first_element = inf;
        long long beauty = 0;
        for (auto x : arr) {
            beauty += x.ss;
            min_second_element = min(min_second_element, x.ss);
            min_first_element = min(min_first_element, x.ff);
        }

        beauty = beauty + min_first_element - min_second_element;
        cout << beauty << "\n";
        arr.clear();
    }

    return 0;
}