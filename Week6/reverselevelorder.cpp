#include<iostream>
#include<queue>
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
    stack<node*> s;
    queue<node*> q;
    q.push(n);
    while(!q.empty())
    {
        node* x = q.front();
        s.push(x);
        q.pop();
        if(x->left)
            q.push(x->left);
        if(x->right)
            q.push(x->right);
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<"->";
        s.pop();
    }
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    reverseLevelOrder(root1);
    return 0;
}

