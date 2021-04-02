#include<iostream>
#include<vector>

using namespace std;

void sort(int a[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++)
    {
        switch(a[i])
        {
            case 0:
            {
                count0++;
                break;
            }
            case 1:
            {
                count1++;
                break;
            }
            case 2:
            {
                count2++;
                break;
            }
        }
    }
    cout<<count0<<count1<<count2;
    int i = 0;
    while(count0 > 0)
    {
        a[i] = 0;
        i++;
        count0--;
    }
    while(count1 > 0)
    {
        a[i] = 1;
        i++;
        count1--;
    }
    while(count2 > 0)
    {
        a[i] = 2;
        i++;
        count2--;
    }

}

int main()
{
    int a[] = {0, 2, 1, 1, 2, 0, 1};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a,n);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}
