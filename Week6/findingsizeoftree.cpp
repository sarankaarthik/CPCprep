#include<iostream>

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
}

int countNodes(node * n)
{
    if(n == NULL)
        return 0;
    else
        return (countNodes(n->left) + countNodes(n->right) + 1);
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    countNodes(root);
}

