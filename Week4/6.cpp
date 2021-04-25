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
        cout<<endl;
    }
};

struct node* merge(struct node* x, struct node* y)
{
    int count = 1;
    List list;
    struct node* temp1 = x;
    struct node* temp2 = y;

    while(temp1 != NULL || temp2 != NULL)
    {
        if(count % 2 != 0)
        {
            list.push(temp1->x);
            temp1 = temp1->next;
        }
        else
        {
            list.push(temp2->x);
            temp2 = temp2->next;
        }
    }
    return list.HEAD;
}

int main()
{
    List list1, list2;
    int n;
    cin>>n;
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        list1.push(i+1);
    }
    list1.printList();
    list2.printList();
    List list;
    list.HEAD = merge(list1.HEAD, list2.HEAD);
    list.printList();
}
