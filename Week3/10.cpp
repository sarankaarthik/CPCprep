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

List inter(List list1, List list2)
{
    List intersection;
    struct node* temp = list1.HEAD;
    map<int,int> hash;
    while(temp != NULL)
    {
        hash[temp->x]++;
        temp = temp->next;
    }
    temp = list2.HEAD;
    while(temp != NULL)
    {
        if(hash[temp->x] != 0)
        {
            intersection.push(temp->x);
        }
        temp = temp->next;
    }
    return intersection;
}

int main()
{
    List list1,list2;
    int n;
    cin>>n;
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        list1.push(i+1);
    }
    for(int i = 1; i < n + 5; i = i + 2)
    {
        list2.push(i);
    }
    list1.printList();
    list2.printList();
    List x = inter(list1,list2);
    x.printList();
}
