#include <iostream>
#include <map>

using namespace std;

struct node{
    int x;
    node* next;
};

class List{
    public:
    struct node* HEAD = NULL;
    struct node* END = NULL;
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
    void printList()
    {
        struct node* temp = HEAD;
        while(temp != NULL)
        {
            cout<<temp->x<<"->";
            temp = temp->next;
        }
    }
};

void delAlt(struct node* x)
{
    if (x == NULL)
        return;
 
    struct node* temp = x->next;
    if (temp == NULL)
        return;

    x->next = temp->next;
    free(temp);
    delAlt(x->next);
}

int main()
{
    List list1;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        list1.push(i+1);
    }
    delAlt(list1.HEAD);
    list1.printList();
}
