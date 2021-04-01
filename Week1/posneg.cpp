#include<iostream>

using namespace std;

void seg(int a[], int n)
{
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (a[j] < 0)
        {
            i++;
            int swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }
    int pos = i+1, neg = 0;
    while (pos < n && neg < pos && a[neg] < 0)
    {
        int swap = a[neg];
        a[neg] = a[pos];
        a[pos] = swap;
        pos++;
        neg += 2;
    }
}


int main()
{
    int a[] = {1,-6,8,7,-5,-8,-3,2};
    int n = sizeof(a)/sizeof(a[0]);
    seg(a,n);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}
