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

        void preOrderTraversal(node* root);
        void inOrderTraversal(node* root);
        void postOrderTraversal(node* root);
        node* buildTree(int *postOrder, int *inOrder , int start, int end);
        int search(int *inOrder, int start, int end , int curr);
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

node* node::buildTree(int *postOrder, int *inOrder , int start, int end){
    static int idx = 4;

    if(start>end)
        return NULL;

    int val = postOrder[idx];
    idx--;
    node* curr = new node(val);

    if(start==end)
        return curr;

    int pos = curr->search(inOrder, start, end , val);

    curr->right = buildTree(postOrder,inOrder, pos+1, end);
    curr->left = buildTree(postOrder,inOrder,start, pos-1);

    return curr;
}

int node::search(int *inOrder, int start, int end, int curr){
    int i = start;
    while(i<=end){
        if(inOrder[i]==curr)
            return i;
        i++;
    }
    return -1;
}



int main(){
    int postOrder[] = {4,2,5,3,1};
    int inOrder[] = {4,2,1,5,3};

    node* root = root->buildTree(postOrder,inOrder, 0 ,4);
    root->inOrderTraversal(root);
    return 0;
}