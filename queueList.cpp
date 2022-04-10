#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int val){
            data = val;
            next = NULL;
        }
};

class queue{
    node* front;
    node* back;

    public:
        queue(){
            front = NULL;
            back = NULL;
        }

        void Enqueue(int val){
            node* n = new node(val);

            if(front==NULL){
                back = n;
                front = n;
                return;
            }

            back->next = n;
            back = n;
        }

        void dequeue(){
            if(front==NULL){
                cout<<"Queue khaali !\n";
                return;
            }
            node* todelete = front;
            front = front->next;
            delete todelete;
        }

        int peeK(){
            if(front==NULL){
                cout<<"Queue khaali !\n";
                return -1;
            }
            return front->data;
        }

        bool empty(){
            if(front==NULL){
                // cout<<"Queue khaali !\n";
                return true;;
            }
            return false;
        }
};

int main(){
    queue a;
    a.Enqueue(10);
    a.Enqueue(20);
    a.Enqueue(30);
    cout<<a.peeK()<<endl;
    return 0;
}