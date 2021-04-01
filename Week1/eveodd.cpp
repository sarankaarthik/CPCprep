#include<iostream>

using namespace std;

void seg(int a[], int n)
{
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (a[j] % 2 == 0)
        {
            i++;
            int swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }
}


int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    seg(a,n);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}
