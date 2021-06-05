#include<iostream>
#include<map>

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

void printbstkeys(node* n, int k1, int k2)
{
    if(!n)
        return;
    if(k1 < n->data)
        printbstkeys(n->left,k1,k2);
    if (k1 <= n->data && k2 >= n->data)
        cout<<n->data<<" ";
    if(k2 > n->data)
        printbstkeys(n->right,k1,k2);
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
    printbstkeys(root, 2, 6);
}

