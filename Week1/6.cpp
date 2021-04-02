#include<iostream>
#include<map>

using namespace std;

void twice(int a[], int n)
{
    map<int, int> h;
    for(int i = 0; i < n; i++)
    {
        h[a[i]]++;
    }
    for(int i = 1; i < n+1; i++)
    {
        if(h[i] == 0)
        {
            cout<<"\n The number missing is : "<<i;
        }
        else if(h[i] != 1)
        {
            cout<<"\n The number repeating twice is : "<<a[i];
        }
    }

}

int main()
{
    int a[] = {1,3,5,4,4,6};
    int n = sizeof(a)/sizeof(a[0]);
    twice(a,n);
}
