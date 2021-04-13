#include <iostream>

using namespace std;

struct node{
    int x;
    node* next;
};

struct node* HEAD = NULL;
struct node* END = NULL;

void printReverse(struct node* n)
{
    if(n->next == NULL)
        return;
    struct node* temp;
    temp = n;
    n = n->next;
    printReverse(n);
    cout<<n->x<<" ";
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
    printReverse(HEAD);
}
