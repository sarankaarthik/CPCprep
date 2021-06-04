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

void min(node* n)
{
    while(n->left)
        n = n->left;
    cout<<n->data;
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
    min(root);
}

