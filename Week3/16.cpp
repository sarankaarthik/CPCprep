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

List sortedMerge(List list1, List list2)
{
    struct node* temp1 = list1.HEAD;
    struct node* temp2 = list2.HEAD;
    List x;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->x <= temp2->x)
        {
            x.push(temp1->x);
            temp1 = temp1->next;
        }
        else
        {
            x.push(temp2->x);
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL)
    {
        x.push(temp1->x);
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        x.push(temp2->x);
        temp2 = temp2->next;
    }
    return x;
}

int main()
{
    List list1, list2;
    int n;
    cin>>n;
    cout<<endl;
    for(int i = 0; i < n; i = i + 2)
    {
        list1.push(i);
    }
    for(int i = 1; i < n; i = i + 2)
    {
        list2.push(i);
    }
    list1.printList();
    list2.printList();
    List sorted = sortedMerge(list1,list2);
    sorted.printList();
}
