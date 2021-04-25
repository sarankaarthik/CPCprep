#include <bits/stdc++.h>

using namespace std; 

void swap(int* x, int* y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
int partition (int a[], int low, int high) 
{ 
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    { 
        if (a[j] < pivot) 
        { 
            i++;
            swap(&a[i], &a[j]); 
        } 
    } 
    swap(&a[i + 1], &a[high]); 
    return (i + 1); 
} 

void quickSort(int a[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pivot = partition(a, low, high); 
        quickSort(a, low, pivot - 1); 
        quickSort(a, pivot + 1, high); 
    } 
} 
  
int main() 
{ 
    int a[] = {1,5,3,4,8,6,2}; 
    int n = sizeof(a) / sizeof(a[0]); 
    quickSort(a, 0, n - 1); 
    cout << "Sorted array: "; 
    for (int i = 0; i < n; i++) 
        cout << a[i] << " "; 
    cout << endl; 
} 
