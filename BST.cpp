// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node{                     // class to represent the node of the tree
public:                         // setting all attributes as public
    int data;                   // data to be set in the node
    node* left;                 // left pointer of the node
    node* right;                // right pointer of the node
    node(int val){              // constructor with a parameter as value
        data = val;             // setting the data of node as the value taken
        left = NULL;            // Making the left and right child of the node
        right = NULL;           // as NULL
    }

    node* insertBST(node* root, int val); // function to insert in the binary search tree
    void inOrderTraversal(node* root);  // function to print inorder traversal of tree
    void searchBST(node* root, int key); // function to search in BST
    node* deleteBST(node* root, int key); // function to delete in BST
    node* inorderSuccessor(node* root);
};

node* node::insertBST(node* root, int val){// taking root and value as parameters

    if(root == NULL){       // if root is null then we just simply return a new
        return new node(val);   // node with the value
    }

    if(val < root->data){   // if value of root is less then proceed with the left part of the tree
        root->left = insertBST(root->left,val); 
    }
    else{   // else the value is greater then root so proceed with the right half of the tree
        root->right = insertBST(root->right, val);
    }
    return root; // return the root of the tree
}

void node::inOrderTraversal(node* root){ // inorder traversal with root as parameter
    if(root==NULL)  // if root is null then just simply return as there is nothing to print
        return;
    
    inOrderTraversal(root->left); // traverse the left part of tree
    cout<<root->data<<" ";        // print data of root
    inOrderTraversal(root->right);// traverse right part of the tree
}

void node::searchBST(node* root, int key){
    if(root == NULL){
        cout<<"\nElement not found :(";
        return ;
    }
    
    if(root->data == key){
        cout<<"\nElement "<< key <<" Found !";
    }
    else if(root->data > key){
        searchBST(root->left , key);
    }
    else if(root->data < key){
        searchBST(root->right , key);
    }
}

node* node::inorderSuccessor(node* root){
    node* curr = root;
    while(curr != NULL && curr->left != NULL){
        curr = curr->left;
    }

    return curr;
}

node* node::deleteBST(node* root, int key){
    if(root->data > key){
        deleteBST(root->left , key);
    }
    else if(root->data < key){
        deleteBST(root->right , key);
    }
    else{
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

int main(){
    node* root = NULL;
    root = root->insertBST(root,5);
    root->insertBST(root,1);
    root->insertBST(root,3);
    root->insertBST(root,4);
    root->insertBST(root,2);
    root->insertBST(root,7);
    root->inOrderTraversal(root);
    // root->searchBST(root,1);
    // root->searchBST(root,7);
    // root->searchBST(root,11);
    root->deleteBST(root,5);
    root->inOrderTraversal(root);
    return 0;
}