#include <iostream>

using namespace std;

int find(int a[], int n)
{
    int i, sum = 1;
    for (i = 2;  i <= (n+1); i++)
    {
        sum += i;
        sum -= a[i-2];
    }
    return sum;
}
 
int main()
{
    int a[] = {3, 2, 1, 5, 6 ,7};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"\n Missing number from 1 to "<<n+1<<" in the array is : "<<find(a,n);
}
