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

bool check(node* n, int i, int *leaflevel)
{
    if(!n)
        return true;
    if(!n->left && !n->right)
    {
        if(!*leaflevel)
        {
            *leaflevel = i;
            return true;
        }
        return (i == *leaflevel);
    }
    return check(n->left,i++,leaflevel) && check(n->right,i++,leaflevel);
}

bool level(node* n)
{
    int i = 0;
    int leaflevel = 0;
    return check(n, i, &leaflevel);
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    cout<<level(root1);
    return 0;
}

