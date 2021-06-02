#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;    
};  

node* newNode(int x)
{
    node* n = new node();
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void doubleTree(node* n)
{
    node* temp; 
    if (!n)
        return;
    doubleTree(n->left); 
    doubleTree(n->right); 
    temp = n->left; 
    n->left = newNode(n->data); 
    n->left->left = temp; 
}

void inorder(node* n)
{
    if(!n)
        return;
    inorder(n->left);
    cout<<n->data<<"->";
    inorder(n->right);
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    doubleTree(root1);
    inorder(root1);
    return 0;
}

