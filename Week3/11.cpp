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

void intersection(List list1, List list2)
{
    map<int,int> hash;
    struct node* temp = list1.HEAD;
    while(temp != NULL)
    {
        hash[temp->x]++;
        temp = temp->next;
    }
    temp = list2.HEAD;
    cout<<"\nIntersecting elements : ";
    while(temp != NULL)
    {
        if(hash[temp->x] == 1)
        {
            cout<<temp->x<<" ";
        }
        temp = temp->next;        
    }
    cout<<endl;
}

void Union(List list1, List list2)
{
    map<int,int> hash;
    struct node* temp = list1.HEAD;
    cout<<"\nUnion : ";
    while(temp != NULL)
    {
        hash[temp->x]++;
        cout<<temp->x<<" ";
        temp = temp->next;
    }
    temp = list2.HEAD;
    while(temp != NULL)
    {
        if(hash[temp->x] != 1)
            cout<<temp->x<<" ";
        temp = temp->next;        
    }
    cout<<endl;
}

int main()
{
    List list1, list2;
    list1.push(2);
    list1.push(3);
    list1.push(5);
    list1.push(6);
    list2.push(1);
    list2.push(2);
    list2.push(4);
    list2.push(6);
    intersection(list1,list2);
    Union(list1,list2);
}
