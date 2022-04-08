#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
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

node *insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    node *temp = head;
    while (temp->next != NULL)
    {
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

node *reverseK(node *&head, int k)
{
    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr;

    int count = 0;
    while (currPtr != NULL && count < k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }

    if (nextPtr != NULL)
        head->next = reverseK(nextPtr, k);

    return prevPtr;
}

int main()
{
    node *head = NULL;
    head = insertAtHead(head, 1);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);
    head = insertAtTail(head, 6);
    displayList(head);
    node* ans = reverseK(head, 2);
    cout<<"--------------------------------------\n";
    displayList(ans);

    return 0;
}