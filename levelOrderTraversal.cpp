#include<iostream>
#include<queue>
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
    void levelOrderTraversal(node* root);
    int sumOfNodesAtKthLevel(node* root, int k);
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

void node::levelOrderTraversal(node* root){
    if(root==NULL)
        return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n!=NULL){
            cout<<n->data<<" ";
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int node::sumOfNodesAtKthLevel(node* root, int k){
    if(root == NULL)
        return -1;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while(!q.empty()){
        node* n = q.front();
        q.pop();

        if(n!=NULL){
            if(level==k)
                sum += n->data;
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    //root->levelOrderTraversal(root);
    cout<<root->sumOfNodesAtKthLevel(root,2);
    return 0;
}