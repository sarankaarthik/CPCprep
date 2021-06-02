#include<iostream>
#include<queue>

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

void levelOrder(node* n, int k, int N)
{
    if(!n)
        return;
    queue<node*> q;
    q.push(n);
    int j = 1;
    while(!q.empty() && j <= N)
    {
        int n = q.size();
        for(int i = 1; i <= n; i++)
        {
            node* x = q.front();
            if(i == k && j == N)
                cout<<x->data<<" ";
            q.pop();
            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
        }
        j++;
    }
}

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    levelOrder(root1,2,3);
    return 0;
}

