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

int main(){
    node* root = NULL;
    root = root->insertBST(root,5);
    root->insertBST(root,1);
    root->insertBST(root,3);
    root->insertBST(root,4);
    root->insertBST(root,2);
    root->insertBST(root,7);
    root->inOrderTraversal(root);
    return 0;
}