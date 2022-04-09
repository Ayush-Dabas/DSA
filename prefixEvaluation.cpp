#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

void PrefixEvaluation(string s){
    stack<int> st;

    for(int i=s.length()-1 ; i>=0 ; i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');

        }
        else{
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            
            case '-':
                st.push(operand1 - operand2);
                break;

            case '*':
                st.push(operand1 * operand2);
                break;

            case '/':
                st.push(operand1 / operand2);
                break;
            
            default:
                break;
            }
        }
    }
    cout<<st.top()<<endl; 
}

int main(){
    string s = "-+7*45+20";
    PrefixEvaluation(s);
    return 0;
}