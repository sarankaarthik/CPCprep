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

struct node* delNodes(struct node* x)
{
    int m, n;
    cin>>m>>n;
    int count = 0;
    struct node* temp = x;
    while(temp != NULL && count != m)
    {
        temp = temp->next;
        count++;
    }
    count = 0;
    struct node* curr = temp->next;
    while(curr != NULL && count != n)
    {
        struct node* temp1 = curr;
        curr = curr->next;
        free(temp1);
        count++;
    }
    temp->next = curr;
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
    delNodes(list.HEAD);
    list.printList();
}
