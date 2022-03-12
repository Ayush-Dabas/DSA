//Find a^b
#include<bits/stdc++.h>
using namespace std;

int A_RaiseToPower_B(int a, int b){
    int ans = 1;

    while(b>0){
        if((b&1)==1)
            ans *= a;
        a *= a;
        b = b >> 1;
    }

    return ans;
}

int A_RaiseToPower_B_Modulo_n(int a, int b, int n){
    int ans = 1;

    while(b>0){
        if((b&1)==1)
            ans = (ans * a % n) % n;
        a = (a % n * a % n) % n;
        b = b >> 1;
    }

    return ans;
}

int main()
{
    cout << A_RaiseToPower_B(2, 5) << endl;
    cout << A_RaiseToPower_B_Modulo_n(3, 5, 2) << endl;
    return 0;
}