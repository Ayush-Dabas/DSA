#include<bits/stdc++.h>
using namespace std;

class node{                             // class to represent tree
public:
    int data;                           // data of the node of the tree
    node* left;                         // left pointer of the node        
    node* right;                        // Right pointer of the node
    node(int val){                      // constructor of the node to generate the node
        data = val;                     // the input of data is taken to be value
        left = NULL;                    // left pointer is defined as NULL
        right = NULL;                   // Right pointer is defined as NULL
    }
};

void printSubTreeNodes(node* root, int k){  //print subtrees with parameters as the root node and distance k
    if(root == NULL || k<0)                 // if root is null then we just return as there is no subtree and if k is -ve then atarimae
        return ;

    if(k==0){                               // if k is 0 then it means that we have found the node then
        cout<<root->data<<" ";              // just print the data of the node and then return 
        return ;
    }

    printSubTreeNodes(root->left, k-1);     // recursively call for the left subtree of the tree with distance as k-1 
    printSubTreeNodes(root->right, k-1);    // same as above but for right subtree
}

int printNodesAtK(node* root, node* target , int k){ // calling the function for a root, the target node from where we start and distance k
    if(root == NULL)                        // if root is null then just return -1 as there is no distance to find
        return -1;

    if(root == target){                     // if root == target then we first print the subtrees of the target node as in above function
        printSubTreeNodes(root,k);
        return 0;
    }

    int dl = printNodesAtK(root->left, target,  k);// take dl as the distance of left node when taking tree as only left of the root
    if(dl != -1){                           // if dl is -1 then this means left subtree was NULL so excluding that 
        if( dl +1 == k){                    // check if dl +1 = k which means that we found the required target and then print the data
            cout<<root->data<<" ";
        }
        else{                               // else then we print subtree nodes for right part and with distance as k - dl - 2
            printSubTreeNodes(root->right, k-dl-2);
        }
        return 1+dl;
    }

    
    int dr = printNodesAtK(root->left,target , k);
    if(dr != -1){
        if( dr +1 == k){
            cout<<root->data<<" ";
        }
        else{
            printSubTreeNodes(root->right, k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);

    printNodesAtK(root, root->left , 1);
    return 0;
}