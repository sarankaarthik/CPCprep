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

struct node* reverseAlt(struct node* x, int k)
{
    if (!x)
        return NULL;
    struct node* current = x;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(x != NULL) 
    x->next = current; 
    count = 0; 
    while(count < k-1 && current != NULL ) 
    { 
        current = current->next; 
        count++; 
    } 
    if(current != NULL) 
        current->next = reverseAlt(current->next, k); 
    return prev; 
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
    int k;
    cin>>k;
    list.printList();
    list.HEAD = reverseAlt(list.HEAD,k);
    list.printList();
}
