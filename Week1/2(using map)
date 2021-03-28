#include<iostream>
#include<map>

using namespace std;

void odd(int a[], int n)
{
    map<int, int> occ;
    for(int i = 0; i < n; i++)
    {
        occ[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(occ[a[i]] % 2 != 0)
        {
            cout<<"\n The number which occurs odd number of times is : "<<a[i];
            break;
        }
    }

}

int main()
{
    int a[] = {1, 2, 3, 2, 2, 3, 1};
    int n = sizeof(a)/sizeof(a[0]);
    odd(a,n);
}
