#include<iostream>
#include<map>

using namespace std;

void dup(int a[], int n)
{
    map<int, int> dup;
    for(int i = 0; i < n; i++)
    {
        if(dup[a[i]] == 0)
            dup[a[i]]++;
        else
            cout<<a[i];

    }

}

int main()
{
    int a[] = {-1, 5, 6, 8, 5, 4};
    int n = sizeof(a)/sizeof(a[0]);
    dup(a,n);
}
