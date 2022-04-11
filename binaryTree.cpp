#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }

        void preOrder(node* root);
        void inOrder(node* root);
        void postOrder(node* root);
};

void node::preOrder(node* root){
    if(root==NULL){
    //cout<<"No element present !\n";
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void node::inOrder(node* root){
    if(root==NULL)
        return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void node::postOrder(node* root){
    if(root==NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->preOrder(root);
    cout<<endl;
    root->inOrder(root);
    cout<<endl;
    root->postOrder(root);
    cout<<endl;
    return 0;
}