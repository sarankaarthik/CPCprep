#include <iostream>

using namespace std;
  
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void bubbleSort(int a[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1]) 
                swap(&a[j], &a[j+1]);
        }
    }
} 
  
int main() 
{ 
    int a[] = {5,4,3,7,5,2,1,8}; 
    int n = sizeof(a)/sizeof(a[0]); 
    bubbleSort(a, n); 
    cout<<"Sorted array: "; 
    for (int i = 0; i < n; i++) 
        cout << a[i] << " "; 
    cout << endl; 
} 
