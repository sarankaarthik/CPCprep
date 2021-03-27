#include<iostream>

using namespace std;
 
void repeat(int a[], int n)
{
    int i, j;
    cout<<"\n Repeating Elements : ";
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] == a[j])
                cout << a[i] << " ";
}
 
 
int main()
{
    int a[] = {7, 5, 6, 4, 8, 4, 9, 3, 7};
    int n = sizeof(a)/sizeof(a[0]);
    repeat(a, n);
}
