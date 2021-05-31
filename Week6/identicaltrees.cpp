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

int identical(node* a, node* b)
{
    if(a == NULL || b == NULL)
    {
        return 1;
    }
    return (a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right));
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    node* root3 = newNode(1);
    root3->right = newNode(2);
    root3->left = newNode(3);
    root3->left->left = newNode(4);
    root3->left->right = newNode(5);

    cout<<identical(root1,root2)<<endl;
    cout<<identical(root2,root3)<<endl;
    return 0;
}

