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

void inorder(node* n, int i, int &eSum, int &oSum)
{
    if(n == NULL)
        return;
    if(i % 2)
        oSum += n->data;
    else
        eSum += n->data;
    i++;
    inorder(n->left, i, eSum, oSum);
    inorder(n->right, i, eSum, oSum);
}

void sum(node* n)
{
    int oSum = 0;
    int eSum = 0;
    inorder(n,1,eSum,oSum);
    cout<<eSum<<" "<<oSum;
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    sum(root1);
    return 0;
}

