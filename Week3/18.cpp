#include <iostream>
#include <map>
#include <random>

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
        cout<<endl;
    }
};

struct node* seg(struct node* n)
{
    List evenList, oddList;
    struct node* temp = n;
    struct node* evenEnd = n;
    while(temp != NULL)
    {
        if(temp->x % 2 == 0)
            evenList.push(temp->x);
        else
            oddList.push(temp->x);
        temp = temp->next;
    }
    evenList.END->next = oddList.HEAD;
    return evenList.HEAD;
}

int main()
{
    List list;
    int n;
    cin>>n;
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        list.push(i+1);
    }
    list.HEAD = seg(list.HEAD);
    list.printList();
}
