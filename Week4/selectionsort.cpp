#include <iostream>

using namespace std;
  
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
void selection(int a[], int n) 
{ 
    int i, j, min;
    for (i = 0; i < n-1; i++) 
    {
        min = i; 
        for (j = i+1; j < n; j++) 
            if (a[j] < a[min]) 
                min = j;
        swap(&a[min], &a[i]); 
    } 
} 

int main() 
{ 
    int a[] = {2,4,3,6,1,8,7}; 
    int n = sizeof(a)/sizeof(a[0]); 
    selection(a, n); 
    cout << "Sorted array: "; 
    for (int i=0; i < n; i++) 
        cout << a[i] << " "; 
    cout << endl; 
    return 0; 
} 
