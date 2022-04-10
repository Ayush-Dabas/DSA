#include<iostream>
#include<string>
#include<math.h>
#include<stack>
#include<algorithm>
using namespace std;

int presedence(char c){
    if(c=='/')
        return 4;
    else if(c=='*')
        return 3;
    else if(c=='+')
        return 2;
    else if(c=='-')
        return 1;
    return 0;
}

string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string res;

    for(int i=0 ; i<s.length() ; i++){
        if(s[i]>='a' && s[i]<='z')
            res += s[i];
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && presedence(st.top())>=presedence(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}