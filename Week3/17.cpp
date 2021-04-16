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

void sort(List list)
{
    struct node* temp = list.HEAD;
    map<int,int> hash;
    while(temp != NULL)
    {
        hash[temp->x]++;
        temp = temp->next;
    }
    temp = list.HEAD;
    int i = 0;
    while(temp != NULL && i < 3)
    {
        for(int j = 0; j < hash[i]; j++)
        {
            temp->x = i;
            temp = temp->next;
        }
        i++;
    }
}

int main()
{
    List list;
    int n;
    cin>>n;
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        list.push(rand() % 3);
    }
    list.printList();
    sort(list);
    list.printList();
}
