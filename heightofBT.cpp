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
    int height(node* root);
    int diameter(node* root);
    int diameter(node* root, int* height);
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

int node::height(node* root){
    if(root==NULL)
        return 0;

    int lheight = root->height(root->left);
    int rheight = root->height(root->right);

    return max(lheight,rheight) + 1;
}

int node::diameter(node* root){

    if(root==NULL)
        return 0;

    int lheight = root->height(root->left);
    int rheight = root->height(root->right);
    int currDiameter = lheight + rheight + 1;

    int ldiameter = root->diameter(root->left);
    int rdiameter = root->diameter(root->right);

    return max(ldiameter,max(rdiameter,currDiameter));
}

int node::diameter(node* root, int* height){

    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = root->diameter(root->left, &lh);
    int rdiameter = root->diameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh,rh) + 1;

    return max(ldiameter,max(rdiameter,currDiameter));

}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<root->height(root)<<endl;
    cout<<root->diameter(root)<<endl;
    int h = 0;
    cout<<root->diameter(root, &h);

    return 0;
}