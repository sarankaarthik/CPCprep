#include<iostream>
#include<map>
#include<limits.h>

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

node* insert(node* node, int x)
{
    if(!node)
        return newNode(x);
    if(x >= node->data)
        node->right = insert(node->right, x);
    if(x < node->data)
        node->left = insert(node->left, x);
    return node;    
}

int childsumtree(node* n)
{
    if(!n->left && !n->right) 
        return 1;
    if(n->left->data + n->right->data == n->data)
        return 1;
    else return 0;
    return childsumtree(n->left) && childsumtree(n->right);
}

int main()
{
    node* root1 = newNode(12);
    root1->left = newNode(9);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    cout<<childsumtree(root1);
}

