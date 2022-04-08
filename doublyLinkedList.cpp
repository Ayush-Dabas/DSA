#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* previous;
        node* next;
        node(int val){
            data = val;
            previous = NULL;
            next = NULL;
        }

        node* insertAtHead(node* &head, int val);
        node* insertAtTail(node* &head, int val);
        void display(node* head);
        void displayReverse(node* head);
        node* deletion(node* &head, int val);
};

node* node::insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head!=NULL)
        head->previous = n;
    return n;
}

node* node::insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->next = NULL;
    n->previous = temp;

    return head;
}

void node::display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void node::displayReverse(node* head){
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    cout<<"NULL<-";
    while(temp!=NULL){
        cout<<temp->data<<"<-";
        temp = temp->previous;
    }
}

node* node::deletion(node* &head, int pos){
    if(pos==1){
        node* temp = head->next;
        temp->previous = NULL;
        free (head);
        return temp;
    }    
    node* temp = head;
    int i = 1;
    while(i!=pos){
        temp = temp->next;
        i++;
    }
    if(temp->next==NULL){
        node* n = temp->previous;
        free(temp);
        n->next = NULL;
        return head;
    }
    else{
        node* n = temp->next;
        node* a = temp->previous;
        free(temp);
        n->previous = a;
        a->next = n;
        return head;
    }
}

int main(){
    node* head = NULL;
    head = head->insertAtHead(head,1);
    head = head->insertAtHead(head,2);
    head = head->insertAtTail(head,4);

    head->display(head);
  //head->displayReverse(head);
    head = head->deletion(head,2);
    head->display(head);
    return 0;
}