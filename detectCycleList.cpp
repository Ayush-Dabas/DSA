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

node *insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;

    return n;
}

node *insertAtTail(node *&head, int val){
    node *n = new node(val);

    node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
    return head;
}

void displayList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow)
            return true;
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow!=fast);

    fast = head;

    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
    
}

int main()
{
    node* head = NULL;
    head = insertAtHead(head,1);
    head = insertAtTail(head,2);
    head = insertAtTail(head,3);
    head = insertAtTail(head,4);
    head = insertAtTail(head,5);
    head = insertAtTail(head,6);
    head = insertAtTail(head,7);

    makeCycle(head,3);
    // displayList(head);
    if(detectCycle(head)==true)
        cout<<"YO ANGELO\n";

    removeCycle(head);
    displayList(head);
    return 0;
}