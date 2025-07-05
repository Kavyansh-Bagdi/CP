#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
    }
    else if (n == 3 || n == 2)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        if (n % 2 == 0)
        {
            for (int num = 2; num <= n; num += 2)
                cout << num << " ";
            for (int num = 1; num < n; num += 2)
                cout << num << " ";
        }
        else
        {
            for (int num = 1; num <= n; num += 2)
                cout << num << " ";
            for (int num = 2; num < n; num += 2)
                cout << num << " ";
        }
    }
    return 0;
}