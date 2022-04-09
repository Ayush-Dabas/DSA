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
        void display(node* head);
};

node* node::insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        n->next = n;
        head = n;
        return head;
    }
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
    return head;
}

node* node::insertAtTail(node* &head, int val){
    if(head==NULL){
        head = head->insertAtHead(head,val);
        return head;
    }
    node* n = new node(val);
    node* temp = head;

    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    return head;
}

void node::display(node* head){
    node* temp = head;
    do
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    } while (temp!=head);
    
    cout<<"NULL\n";
}

int main(){
    node* head = NULL;
    head = head->insertAtHead(head,1);
    head = head->insertAtTail(head,2);
    head = head->insertAtTail(head,3);
    head = head->insertAtTail(head,4);
    head->display(head);
    return 0;
}