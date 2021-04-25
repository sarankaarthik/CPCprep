#include <iostream>

using namespace std;

void insertion(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
 
int main()
{
    int a[] = {1, 5, 6, 3, 8, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    insertion(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
