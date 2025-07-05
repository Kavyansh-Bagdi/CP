#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    long long sum = 0;
    int num;

    for(int i = 0 ; i < n - 1 ; i++){
        cin >> num;
        sum += num;   
    }

    long long actual = (1LL * n * (n + 1)) / 2;

    cout << actual - sum << endl;

    return 0;
}
