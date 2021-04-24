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

int multiply(struct node* x, struct node* y)
{
    int num1 = 0;
    int num2 = 0;
    while (x || y)
    {
        if (x)
        {
            num1 = num1*10 + x->x;
            x = x->next;
        }
        if (y)
        {
            num2 = num2*10 + y->x;
            y = y->next;
        }
    }
    return num1 * num2;
}

int main()
{
    List list1, list2;
    list1.push(2);
    list1.push(4);
    list2.push(2);
    list2.push(1);
    list1.printList();
    list2.printList();
    cout << multiply(list1.HEAD,list2.HEAD);
}
