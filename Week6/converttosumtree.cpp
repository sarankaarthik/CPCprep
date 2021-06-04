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

int leaf(node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

int sumtree(node* node)
{
    int ls, rs; 

    if(node == NULL || leaf(node))
        return 1;
 
    if(sumtree(node->left) && sumtree(node->right))
    {
        if(node->left == NULL)
            ls = 0;
        else if(leaf(node->left))
            ls = node->left->data;
        else
            ls = 2 * (node->left->data);
        if(node->right == NULL)
            rs = 0;
        else if(leaf(node->right))
            rs = node->right->data;
        else
            rs = 2 * (node->right->data);
        node->data = ls + rs;
        return 1;
    }
    return 0;
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
    inorder(root1);
    cout<<endl;
    sumtree(root1);
    inorder(root1);
    return 0;
}

