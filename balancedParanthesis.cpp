#include<iostream>
#include<stack>
using namespace std;

int isMatch(char a, char b){
    if(a=='(' && b==')')
        return 1;
    else if(a=='[' && b==']')
        return 1;
    else if(a=='{' && b=='}')
        return 1;
    return -1;
}

void CheckParanthesis(string s){
    stack<char> st;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(isMatch(st.top(),s[i])){
                st.pop();
            }
        }
    }
    if(st.empty())
        cout<<"Valid string !\n";
    else
        cout<<"Invalid string !\n";
}

int main(){
    string s = "({[])";
    CheckParanthesis(s);
    return 0;
}