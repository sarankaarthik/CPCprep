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

struct node* rotate(List list, int k)
{
    int count = 1;
    struct node* temp = list.HEAD;
    struct node* kthNode = NULL;
    while(temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }
    kthNode = temp;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list.HEAD;
    list.HEAD = kthNode->next;
    kthNode->next = NULL;
    return(list.HEAD);
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
    list.HEAD = rotate(list,k);
    list.printList();
}
