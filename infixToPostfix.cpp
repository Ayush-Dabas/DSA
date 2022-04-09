#include<iostream>
#include<stack>
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

bool isOperator(char c){
    if(c=='/' || c=='*' || c=='+' || c=='-')
        return true;
    return false;
}

string infixToPostfix(string s){
    stack<char> st;
    string res ;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]>='a' && s[i]<='z'){
            res += s[i];
        }
        else if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        if(isOperator(s[i])==true){
            while(!st.empty() && presedence(st.top())>presedence(s[i])){
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
    return res;
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<<infixToPostfix(s)<<endl;
    return 0;
}