// Find palindrome number
#include<bits/stdc++.h>
using namespace std;

int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

int Is_Palindrome(int n){
    if(reverseDigits(n)==n)
        return 1;
    return 0;
}

int main()
{
    int n = 10101;
    cout << Is_Palindrome(n) << endl;
    return 0;
}