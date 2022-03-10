//find 2 non repeating elements in an array
#include<bits/stdc++.h>
using namespace std;

void answer(int *a, int n){
    int res = a[0];
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
        res ^= a[i];
    int setbit = res & ~(res - 1);
    for (int i = 0; i < n; i++){
        if(a[i] & setbit)
            x = x ^ a[i];
        else
            y = y ^ a[i];
    }
    cout << x << " " << y << endl;
}

int main()
{
    int a[] = {5, 4, 1, 4, 3, 5, 1, 2};
    int n = 8;
    answer(a, n);

    return 0;
}