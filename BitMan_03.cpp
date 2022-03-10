//Find ith bit
#include<bits/stdc++.h>
using namespace std;

void FindBit(int n, int i){
    int x = 1 >> i;
    if((n&x)==0)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}

int main()
{
    int n = 5;
    FindBit(n, 1);
    return 0;
}