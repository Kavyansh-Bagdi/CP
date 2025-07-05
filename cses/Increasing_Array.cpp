#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long chg = 0;

    for (int idx = 1; idx < n; idx++)
    {
        if (arr[idx - 1] > arr[idx])
        {
            chg += 1LL * (arr[idx - 1] - arr[idx]);
            arr[idx] = arr[idx-1];
        }
    }

    cout << chg;
    return 0;
}