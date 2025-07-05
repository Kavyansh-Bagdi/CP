#include <bits/stdc++.h>
using namespace std;

int main(){
    string dna;
    cin>>dna;

    int res = 0;
    int size = dna.size();
    int i = 0, j = 0;
    while(j < size){
        if(dna[i] == dna[j]) j++;
        else{
            res = max(res,j - i);
            i = j;
        }
    }

    if(dna[size-1] == dna[i]){
        res = max(res,size-i);
    }

    cout<< res;
    return 0;
}