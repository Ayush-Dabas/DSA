//Clear bit
#include<bits/stdc++.h>
using namespace std;

void ClearBit(int n, int bit){
    int x = 1 << bit;
    x = ~x;
    n = (n & x);
    cout << n << endl;
}

int main()
{
    ClearBit(2, 1);
    return 0;
}