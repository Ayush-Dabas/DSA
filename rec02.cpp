//ways to treavel in nxm matrix
#include<bits/stdc++.h>
using namespace std;

void out(int n){
    cout << "The value is : " << n << endl;
}

int ways(int n, int m){
    if(n==1||m==1)
        return 1;
    return ways(n - 1, m) + ways(n, m - 1);
}

int main()
{
    int n,m;
    cin >> n;
    // out(n);
    cin >> m;
    // out(m);
    out(ways(n, m));
    return 0;
}