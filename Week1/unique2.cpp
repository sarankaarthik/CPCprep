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
        if(h[i] == 1)
        {
            cout<<"\n The unique number is : "<<i;
        }
    }

}

int main()
{
    int a[] = {1,2,1,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);
    twice(a,n);
}
