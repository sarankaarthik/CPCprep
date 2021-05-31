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
    return n;
}

void preorder(node* n)
{
    if(n == NULL)
        return;
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
}

void inorder(node* n)
{
    if(n == NULL)
        return;
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}

void postorder(node* n)
{
    if(n == NULL)
        return;
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    preorder(root1);
    cout<<endl;
    inorder(root1);
    cout<<endl;
    postorder(root1);

    return 0;
}

