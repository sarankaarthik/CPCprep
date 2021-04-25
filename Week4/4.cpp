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

int count(struct node* x)
{
    int count = 0;
    while (x != NULL)
    {
        count++;
        x = x->next;
    }
    return count;
}
  
void swap(struct node* x, int k)
{
    int n = count(x);
    struct node* temp1 = x;
    struct node* prev1 = NULL;
    for (int i = 1; i < k; i++)
    {
        prev1 = temp1;
        temp1 = temp1->next;
    }

    struct node* temp2 = x;
    struct node* prev2 = NULL;

    for (int i = 1; i < n - k + 1; i++)
    {
        prev2 = temp2;
        temp2 = temp2->next;
    }
    if (prev1)
        prev1->next = temp2;
    if (prev2)
        prev2->next = temp1;
    struct node* c = temp1->next;
    temp1->next = temp2->next;
    temp2->next = c;

    if (k == 1)
        x = temp2;
    if (k == n)
        x = temp1;
}

int main()
{
    List list;
    cout<<endl;
    for(int i = 0; i < 10; i++)
    {
        list.push(i+1);
    }
    int k;
    cin>>k;
    list.printList();
    swap(list.HEAD,k);
    list.printList();
}
