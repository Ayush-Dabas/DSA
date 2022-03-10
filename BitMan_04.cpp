// Set bit
#include<bits/stdc++.h>
using namespace std;

void Set_bit(int n, int bit, int value){
    int x = value << bit;
    n = (n | x);
    cout << n << endl;
}

int main()
{
    Set_bit(8, 1, 1);
    return 0;
}