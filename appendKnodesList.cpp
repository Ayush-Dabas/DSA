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

        node* insertAtHead(node* &head, int val);
        node* insertAtTail(node* &head, int val);
        void display(node* &head);
        node* appendKnodes(node* &head, int k);
        int length(node* &head);
};

node* node::insertAtHead(node* &head, int val){
    node* temp = new node(val);
    temp->next = head;
    return temp;
}

node* node::insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    // n->next = NULL;
    return head;
}

void node::display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int node::length(node* &head){
    node* temp = head;
    int l = 0;
    while(temp!=NULL){
        temp = temp->next;
        l++;
    }
    return l;
}

node* node::appendKnodes(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = head->length(head);
    k = k%l;
    int count = 1;

    while(tail->next!=NULL){
        if(count==l-k){
            newTail = tail;
        }
        if(count==l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main(){
    node* head = NULL;
    head = head->insertAtHead(head,1);
    head = head->insertAtHead(head,3);
    head = head->insertAtTail(head,2);
    head = head->insertAtTail(head,6);
    head = head->insertAtTail(head,4);
    
    head = head->appendKnodes(head,3);

    head->display(head);

    return 0;
}