#include <iostream>

using namespace std;

struct node{
    int x;
    node* next;
};

struct node* HEAD = NULL;
struct node* END = NULL;

void nthNodeFromLast(int n)
{
    int len = 0, i;
    struct node* temp = HEAD;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    cout<<len;
    temp = HEAD;
    for(int i = 1; i < len - n + 1; i++)
    {
        temp = temp->next;
    }
    cout<<temp->x;
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
    nthNodeFromLast(6);
}
