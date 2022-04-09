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
        void displayList(node* head);
        node* merge(node* &head1, node* &head2);
};

node* node::insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    return n;
}

node* node::insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    return head;
}

void node::displayList(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

node* node::merge(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1!=NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode->next;
}

int main(){
    node* head = NULL;
    head = head->insertAtHead(head,1);
    head = head->insertAtTail(head,3);
    head = head->insertAtTail(head,5);
    head = head->insertAtTail(head,7);
    head = head->insertAtTail(head,9);

    node* head2 = NULL;
    head2 = head2->insertAtHead(head2,2);
    head2 = head2->insertAtTail(head2,4);
    head2 = head2->insertAtTail(head2,6);
    head2 = head2->insertAtTail(head2,8);
    head2 = head2->insertAtTail(head2,10);

    node* newHead = newHead->merge(head,head2);
    newHead->displayList(newHead);

    return 0;
}