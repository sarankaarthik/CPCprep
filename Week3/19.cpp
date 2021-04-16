#include <iostream>
#include <map>
#include <random>

using namespace std;

struct node{
    char x;
    node* next;
};

class List{
    public:

    struct node* HEAD = NULL;
    struct node* END = NULL;

    template<typename T>

    T push(T x)
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
        cout<<endl<<endl;
    }
};

struct node* segConsVow(struct node* n)
{
    List vowList, consList;
    struct node* temp = n;
    struct node* evenEnd = n;
    while(temp != NULL)
    {
        if(temp->x == 'a' || temp->x == 'e' || temp->x == 'i' || temp->x == 'o' || temp->x == 'u')
            vowList.push(temp->x);
        else
            consList.push(temp->x);
        temp = temp->next;
    }
    vowList.END->next = consList.HEAD;
    return vowList.HEAD;
}

int main()
{
    List list;
    cout<<endl;
    list.push<char>('a');
    list.push<char>('r');
    list.push<char>('h');
    list.push<char>('i');
    list.push<char>('o');
    list.push<char>('s');
    list.printList();
    list.HEAD = segConsVow(list.HEAD);
    list.printList();
}
