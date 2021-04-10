#include <bits/stdc++.h>

using namespace std;
 
int max(int a[], int n)
{
    map<int, int> h;
 
    int sum = 0;
    int max_len = 0;
    int ending_index = -1;
 
    for (int i = 0; i < n; i++)
        a[i] = (a[i] == 0) ? -1 : 1;
 
 
    for (int i = 0; i < n; i++)
    {
        sum += a[i]; 
        if (sum == 0) 
        {
            max_len = i + 1;
            ending_index = i;
        }
        if (h.find(sum) != h.end())
        {
            if (max_len < i - h[sum]) {
                max_len = i - h[sum];
                ending_index = i;
            }
        }
        else
            h[sum] = i;
    }
 
    for (int i = 0; i < n; i++)
        a[i] = (a[i] == -1) ? 0 : 1;
 
    cout<< ending_index - max_len + 1 << ending_index;
 
    return max_len;
}

int main()
{
    int a[] = { 1, 0, 0, 1, 0, 1, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    max(a, n);
}
