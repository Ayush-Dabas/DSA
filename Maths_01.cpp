// factorial of a number
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==1)
        return 1;
    return n * factorial(n - 1);
}

int Find_Zeros_in_Factorials(int n){
    int ans = 0;
    for (int i = 2; i <= n; i+=5){
        ans ++;
    }
    return ans;
}

int main()
{
    int n = 10;
    cout << factorial(n) << endl;
    cout << Find_Zeros_in_Factorials(n);
    return 0;
}