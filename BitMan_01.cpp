// Find whether the number is even or odd
#include<bits/stdc++.h>
using namespace std;

void IsEven(int n){
    if((n&1)==0)
        cout << "The number " << n << " is even !\n";
    else
        cout << "The number " << n << " is odd !\n";
}

int main()
{
    IsEven(5);
    IsEven(8);
    return 0;
}