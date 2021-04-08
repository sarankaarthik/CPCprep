#include<iostream>

using namespace std;

#define n 4

void rowcol(int a[n][n], int x)
{
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (a[i][j] == x)
        {
            cout << "Element found at position " << i << "," << j;
            return;
        }
        if (a[i][j] > x)
            j--;
        else
            i++;
    }
}

int main()
{
    int a[n][n] = {   { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 }};
    int x = 25;
    rowcol(a,x);
}
