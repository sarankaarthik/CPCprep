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

void alternate(struct node* x)
{
    List list1, list2;
    struct node* temp = x;
    int count = 1;
    while(temp != NULL)
    {
        if(count % 2 != 0)
        {
            list1.push(temp->x);
        }
        else
        {
            list2.push(temp->x);
        }
        temp = temp->next;
        count++;
    }
    list1.printList();
    list2.printList();
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
    list.printList();
    alternate(list.HEAD);
}
