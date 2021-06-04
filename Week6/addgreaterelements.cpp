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

void greatersum(node* n, int* sum)
{
    if(!n)
        return;
    
    greatersum(n->right, sum);

    *sum += n->data;
    n->data = *sum;

    greatersum(n->left, sum);
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
    node* root = NULL;
    root = insert(root,5);
    insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,6);
    insert(root,7);
    inorder(root);
    cout<<endl;
    int sum = 0;
    greatersum(root,&sum);
    inorder(root);
}

