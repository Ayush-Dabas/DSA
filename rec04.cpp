#include<bits/stdc++.h>
using namespace std;

string SWAP(string s, int l, int i){
    swap(s[l], s[i]);
    return s;
}

//wether the string is palindrome or not
bool isPalindrome(string s, int l, int r){
    if(l>r)
        return true;
    if(s[l]!=s[r])
        return false;
    return isPalindrome(s, l + 1, r - 1);
}

//superset of a given string
void PowerSet(string s, int i, string curr){
    if(i==s.length()){
        cout << curr << "\n";
        return;
    }
    PowerSet(s, i + 1, curr + s[i]);
    PowerSet(s, i + 1, curr);
}

//permutations of a string
void Permutation(string s, int l, int r){
    if(l==r){
        cout << s << endl;
        return;
    }
    for (int i = l; i <= r; i++){
        s = SWAP(s, l, i);
        Permutation(s, l + 1, r);
        s = SWAP(s, l, i);
    }
}

int main()
{
    string s = "abc";
    cout << isPalindrome(s, 0, 2) << endl;
    PowerSet(s, 0, "");
    Permutation(s, 0, 2);
    return 0;
}