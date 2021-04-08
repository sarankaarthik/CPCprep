#include<iostream>
#include<time.h>
#include<random>

using namespace std;

void randomize(int a[], int n) 
{ 
    srand (time(NULL)); 
    for (int i = n - 1; i > 0; i--) 
    { 
        int j = rand() % (i + 1); 
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    } 
}

int main()
{
    int a[] = {5,6,2,3,1,4};
    int n = sizeof(a)/sizeof(a[0]);
    randomize(a,n);
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}
