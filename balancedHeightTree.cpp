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

        bool isBalanced(node* root);
        int height(node* root);
        bool isBalanced2(node* root, int* height);
};

int node::height(node* root){
    if(root == NULL)
        return 0;
    
    return max(height(root->left), height(root->right)) + 1;
}

bool node::isBalanced(node* root){

    if(root == NULL)
        return true;

    if(root->isBalanced(root->left) == false)
        return false;

    if(root->isBalanced(root->right) == false)
        return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)>1)
        return false;
    return true;       
}

bool node::isBalanced2(node* root, int* height){
    if(root == NULL)
        return true;   

    int lh = 0, rh = 0;
    if(isBalanced2(root->left, &lh) == false)
        return false;
    if(isBalanced2(root->right, &rh) == false)
        return false;
    
    *height = max(lh,rh) + 1;
    if(abs(lh-rh)>1)
        return false;
    return true;  
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->right = new node(5);
    cout<<root->isBalanced(root)<<endl;
    int height = 0;
    cout<<root->isBalanced2(root, &height)<<endl;
    return 0;
}