#include<iostream>
using namespace std;

#define n 20

class queue{
    int* arr;
    int front;
    int back;

    public:
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        bool isEmpty();
        bool isFull();
        void Enqueue(int val);
        void Dequeue();
        int peek();
};

bool queue::isEmpty(){
    if(front==-1 || front>back)
        return true;
    return false;
}

bool queue::isFull(){
    if(back==n-1)
        return true;
    return false;
}

void queue::Enqueue(int val){
    if(isFull()){
        cout<<"Queue is Full !\n";
        return;
    }
    back++;
    arr[back] = val;

    if(front==-1)
        front++;
}

void queue::Dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty この　バカ!\n";
        return;
    }
    front++;
}

int queue::peek(){
    if(isEmpty()){
        cout<<"Queue is empty この　バカ!\n";
        return -1;
    }
    return arr[front];
}

int main(){
    queue q;
    q.Dequeue();
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    cout<< q.peek() << endl;
    return 0;
}