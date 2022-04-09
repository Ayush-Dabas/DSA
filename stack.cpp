#include<iostream>
using namespace std;

#define n 100

class stack{
        int* arr;
        int top;
    public:
        stack(){
            arr = new int[n];
            top = -1;
        }

        bool isEmpty();
        bool isFull();
        void push(int val);
        void pop();
        int topElement();
        void display();
};

bool stack::isEmpty(){
    if(top==-1)
        return true;
    return false;
}

bool stack::isFull(){
    if(top==n-1)
        return true;
    return false;
}

void stack::push(int val){
    if(isFull()==true){
        cout<<"Stack Overflow !\n";
        return;
    }

    top++;
    arr[top] = val; 
}

void stack::pop(){
    if(isEmpty()==true){
        cout<<"Stack Empty\n";
        return;
    }
    top--;
}

int stack::topElement(){
    if(isEmpty()==true){
        cout<<"Stack Empty\n";
        return 0;
    }
    return arr[top];
}

void stack::display(){
    if(isEmpty()==true){
        cout<<"Stack empty !\n";
        return;
    }
    int i = 0;
    while(i<=top){
        cout<<"Element "<<i+1<<" is : "<<arr[i]<<endl;
        i++;
    }
}

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    cout<<"Top element is "<<s.topElement()<<endl;
    s.display();
    return 0;
}