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

int height(node * n)
{
    if(n == NULL)
    {
        return 0;
    }
    else
    {
        int d1 = height(n->left);
        int d2 = height(n->right);
        if(d1 > d2)
            return d1+1;
        else return d2+1;
    }
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    height(root);
}

