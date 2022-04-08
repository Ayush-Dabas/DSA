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
        int lengthOfList(node* &head);
        int intersectionOf2Lists(node* &head1, node*&head2);
};

node* node::insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    return n;
}

node* node::insertAtTail(node* &head, int val){
    node* n =new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
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

int node::lengthOfList(node* &head){
    node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

int node::intersectionOf2Lists(node* &head1, node* &head2){
    int l1 = head1->lengthOfList(head1);
    int l2 = head2->lengthOfList(head2);
    node* ptr1;
    node* ptr2;
    int d ;
    if(l1>l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL)
            return -1;
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2)
            return ptr1->data;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main(){
    node* head = NULL;
    head = head->insertAtHead(head,1);
    int a[] = {2,3,4,5,6,7};
    for(int i=0 ; i<6 ; i++)
        head = head->insertAtTail(head,a[i]);

    node* head2 = NULL;
    head2 = head2->insertAtHead(head2,1);
    int b[] = {8,9,10,11,12,13};
    for(int i=0 ; i<6 ; i++)
        head2 = head2->insertAtTail(head2,b[i]);

    cout<<head->intersectionOf2Lists(head,head2);
    
  //head->display(head);
  //cout<<head->lengthOfList(head);
    return 0;
}