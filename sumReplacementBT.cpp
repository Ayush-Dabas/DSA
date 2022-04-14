#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
    void preOrderTraversal(node* root);
    void inOrderTraversal(node* root);
    void postOrderTraversal(node* root);
    int sumNodes(node* root);
    void sumReplacementBT(node* root);
};

void node::preOrderTraversal(node* root){
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void node::inOrderTraversal(node* root){
    if(root==NULL)
        return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void node::postOrderTraversal(node* root){
    if(root==NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int node::sumNodes(node* root){
    if(root==NULL)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

void node::sumReplacementBT(node* root){
    if(root == NULL)
        return;

    root->sumReplacementBT(root->left);
    root->sumReplacementBT(root->right);    

    if(root->left!=NULL)
        root->data += root->left->data;
    if(root->right!=NULL)
        root->data += root->right->data;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->preOrderTraversal(root);
    cout<<endl;
    root->sumReplacementBT(root);
    cout<<endl;
    root->preOrderTraversal(root);
    return 0;
}