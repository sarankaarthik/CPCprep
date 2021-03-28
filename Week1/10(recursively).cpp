#include<iostream>

using namespace std;

void reverse(int a[], int start, int end)
{
    if(start > end)
    {
        return;
    }
    else
    {
        int swap = a[start];
        a[start] = a[end];
        a[end] = swap;
        reverse(a,start+1,end-1);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    reverse(a,0,n-1);
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}
