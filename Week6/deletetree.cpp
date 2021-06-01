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

void deleteTree(node* n)
{
    if(!n)
        return;
    deleteTree(n->left);
    deleteTree(n->right);
    cout<<"\n Deleting node : "<<n->data;
    free(n);
    cout<<endl;
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    deleteTree(root1);
    return 0;
}

