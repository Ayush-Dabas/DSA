#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    
public:

    void Enqueue(int val){
        s1.push(val);
    }

    int dequeue(){

        if(s1.empty() && s2.empty()){
            cout<<"Queue empty !\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty(){
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};

int main(){
    queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}