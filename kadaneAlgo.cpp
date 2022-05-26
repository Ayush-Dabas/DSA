#include <bits/stdc++.h>
using namespace std;

void naiveApproach(int *a, int n){
    int maxTillNow = 0;
    int maxFinal = a[0];
    for (int i = 0; i < n; i++){
        // maxTillNow = +a[i];
        for (int j = i ; j < n; j++){
            maxTillNow += a[j];
            maxFinal = max(maxFinal, maxTillNow);
            cout << "Max till now  " << maxTillNow << "  i : " << i << endl;
        }
        maxTillNow = 0;
    }
    cout << maxFinal << endl;
}

void kadaneAlgo(int *a, int n){
    int maxSoFar = a[0],s=0;
    int maxEndHere = 0, start, end;
    for (int i = 0; i < n; i++){
        maxEndHere += a[i];
        if(maxEndHere>maxSoFar){
            maxSoFar = maxEndHere;
        }
        if(maxEndHere < 0){
            maxEndHere = 0;
            s = i + 1;
        }
    }
    cout << maxSoFar << endl;
}

int main(){
    int a[5] = {1, 2, -5, 10, -20};
    naiveApproach(a, 5);
    // kadaneAlgo(a, 5);
    return 0;
}