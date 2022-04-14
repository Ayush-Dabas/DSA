#include<iostream>
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
    int countNodes(node* root);
    int sumNodes(node* root);
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

int node::countNodes(node* root){
    if(root==NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int node::sumNodes(node* root){
    if(root==NULL)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<root->countNodes(root)<<endl;
    cout<<root->sumNodes(root)<<endl;
    return 0;
}