#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element){
    
    if(s.empty()){
        s.push(element);
        return;
    }
    
    int topele= s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(topele);
}

void reverseStack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int element = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,element);
}

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}