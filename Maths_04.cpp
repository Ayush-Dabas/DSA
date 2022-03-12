//GCD 
#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
    // if(a==0 || b==0){
    //     return max(a, b);
    // }
    // return GCD(a - b, b);
    if(b==0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    cout << GCD(24, 8) << endl;
    return 0;
}