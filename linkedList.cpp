#include<bits/stdc++.h>
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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

node* deleteAtHead(node* head){
    node* n = head;
    head = n->next;
    free(n);
    return head;
}

void deleteInTail(node* &head){
    node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    delete temp;
}

void deleteInLinkedlist(node* &head, int val){
    
    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        head = deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* n = temp->next;
    if(n->next==NULL){
        deleteInTail(head);
        return;
    }
    temp->next = temp->next->next;

    delete n;
}

void displayList(node* head){
    node* temp = head;
    int i=1;
    while(temp!=NULL){
        cout<<"Element "<<i<<" is -> "<<temp->data<<endl;
        temp = temp->next;
        i++;
        if(i>=10){
            break;
        }
    }
    cout<<"NULL\n";
}

bool linearSearch(node* head, int val){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==val){
            return true;
        }
        temp= temp->next;
    }
    return false;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,5);
    //deleteInLinkedlist(head,2);
    head = deleteAtHead(head);
    displayList(head);
    return 0;
}