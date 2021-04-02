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
        if(h[i] > n/3)
        {
            cout<<"\n The number occuring more than n/3 : "<<i;
        }
    }

}

int main()
{
    int a[] = {1,3,5,4,4,4,6};
    int n = sizeof(a)/sizeof(a[0]);
    twice(a,n);
}
