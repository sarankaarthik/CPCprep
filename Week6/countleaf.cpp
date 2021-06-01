#include<iostream>
#include<stack>

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

int leaf(node* n)
{
    if(!n)
        return 0;
    if(!n->left && !n->right)
        return 1;
    return leaf(n->left) + leaf(n->right);
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    cout<<leaf(root1);
    return 0;
}

