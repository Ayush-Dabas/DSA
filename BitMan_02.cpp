//swap two nos
#include<bits/stdc++.h>
using namespace std;

void SWAP(int &a, int &b){
    a = (a ^ b);
    b = (a ^ b);
    a = (a ^ b);
}

int main()
{
    int a = 5;
    int b = 10;
    SWAP(a, b);
    cout << a << " " <<b << endl;
    return 0;
}