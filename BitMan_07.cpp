// Find the only non repeating element in array
#include<bits/stdc++.h>
using namespace std;

void solve(int *a, int n){
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= a[i];
    cout << res << endl;
}

int main()
{
    int a[] = {5, 4, 1, 4, 3, 5, 1};
    solve(a, 7);
    return 0;
}