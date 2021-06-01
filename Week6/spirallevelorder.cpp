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

void reverseLevelOrder(node* n)
{
    if(!n)
        return;
    stack<node*> s1;
    stack<node*> s2;
    s1.push(n);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            cout<<s1.top()->data<<" ";
            s2.push(s1.top()->left);
            s2.push(s1.top()->right);
            s1.pop();
        }
        while(!s2.empty())
        {
            cout<<s2.top()->data<<" ";
            s1.push(s2.top()->right);
            s1.push(s2.top()->left);
            s2.pop();
        }
    }
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->left->right->left = newNode(6);
    root1->left->right->right = newNode(7);
    root1->left->left->right = newNode(8);
    reverseLevelOrder(root1);
    return 0;
}

