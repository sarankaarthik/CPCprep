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

void inorder(node* n, int d, map<int,int> &vSum)
{
    if(n == NULL)
        return;
    inorder(n->left,d-1,vSum);
    vSum[d] += n->data;
    inorder(n->right,d+1,vSum);
}

void verticalSum(node* n)
{
    map<int,int> vSum;
    inorder(n,0,vSum);

    for(map<int,int>::iterator it = vSum.begin(); it != vSum.end(); it++)
    {
        cout<<it->first<<":"<<it->second<<" ";
    }
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    verticalSum(root1);
    return 0;
}

