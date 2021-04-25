#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}

int main()
{
    int a[] = {1,5,2,3,4,8,7};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n - 1);
    cout << "\nSorted array is ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
