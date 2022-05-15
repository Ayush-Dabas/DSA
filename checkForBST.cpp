#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBST(node *root, node* MIN = NULL, node* MAX = NULL){
    if(root == NULL)
        return true;

    if(MIN != NULL && root->data <= MIN->data)
        return false;
    if(MAX != NULL && root->data >= MAX->data)
        return false;

    bool Left = isBST(root->left, MIN, root);
    bool Right = isBST(root->right, root, MAX);

    return Left and Right;
}

int main(){
    cout << "Family guy\n";
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);

    node *root = new node(2);
    root->left = new node(1);
    root->right = new node(3);

    if(isBST(root, NULL, NULL))
        cout << "YO\n";
    else
        cout << "NO\n";
    return 0;
}