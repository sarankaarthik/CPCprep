#include <iostream>
#include <vector>

using namespace std;
 
int findgcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return findgcd(b, a % b);
}

void leftRotate(int a[], int d,int n)
{
    d = d % n;
    int gcd = findgcd(d, n);
    for (int i = 0; i < gcd; i++)
    {
        int temp = a[i];
        int j = i;
 
        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            a[j] = a[k];
            j = k;
        }
        a[j] = temp;
    }
}
 
int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(a)/sizeof(a[0]);
    leftRotate(a, 2,n);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}
