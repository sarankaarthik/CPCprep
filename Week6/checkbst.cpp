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

int bst(node* node)
{
    return(check(node, INT_MIN, INT_MAX));
}

int check(node* node, int min, int max)
{
    if (!node)
        return 1;
    if (node->data < min || node->data > max)
        return 0;
    return check(node->left, min, node->data - 1) && check(node->right, node->data + 1, max);
}

int main()
{
    node* root = NULL;
    root = insert(root,5);
    insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,6);
    insert(root,7);
    cout<<bst(root);
}

