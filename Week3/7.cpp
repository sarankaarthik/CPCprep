#include <iostream>
#include <map>

using namespace std;

struct node{
    int x;
    node* next;
};

struct node* HEAD = NULL;
struct node* END = NULL;

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
    void deleteList(struct node* head)
    {
        struct node* temp = HEAD;
        struct node* next = NULL;
        while (temp != NULL)
        {
            next = temp->next;
            free(temp);
            temp = next;
        }
        HEAD = NULL;
    }
    void printList(struct node* x)
    {
        struct node* temp = x;
        while(temp != NULL)
        {
            cout<<temp->x;
            temp = temp->next;
        }
    }
};

void middleElement(struct node* x)
{
    struct node* temp = x;
    struct node* mid = x;
    int count = 0;
    while(temp != NULL)
    {
        if(count % 2 != 0)
            mid = mid->next;
        count++;

        temp = temp->next;
    }
    cout<<mid->x;
}

int main()
{
    Node node;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        node.push(i+1);
    }
    middleElement(HEAD);
}
