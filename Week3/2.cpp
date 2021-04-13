#include <iostream>

using namespace std;

struct node{
    int x;
    node* next;
};

struct node* HEAD = NULL;
struct node* END = NULL;

void reverse(struct node* n)
{
    if(n->next == NULL)
    {
        HEAD = n;
        return;
    }
    struct node* temp;
    temp = n;
    n = n->next;
    temp->next = NULL;
    reverse(n);
    n->next = temp;
}

class Node{
    public:
    void push(int x)
    {
        struct node* n = new node();
        n->x = x;
        n->next = NULL;
        if(HEAD == NULL)
        {
            HEAD = n;
            END = n;
        }
        else
        {
            END->next = n;
            END = n;
        }
    }
};

int main()
{
    Node node;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        node.push(i+1);
    }
    reverse(HEAD);
    struct node* temp = HEAD;
    while(temp != NULL)
    {
        cout<<temp->x<<" ";
        temp = temp->next;
    }
}
