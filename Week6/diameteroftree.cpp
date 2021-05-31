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

int height(node * n, int &x)
{
    if(n == NULL)
        return 0;

    int d1 = height(n->left,x);
    int d2 = height(n->right,x);
    x = max(x,d1+d2);
    return max(d1,d2) + 1;
}

int diameter(node* n)
{
    int d = 0;
    height(n,d);
    return d + 1;
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout<<diameter(root);
}
