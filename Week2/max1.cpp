#include<iostream>
#include<map>

using namespace std;

#define r 4
#define c 4

void max1(int a[r][c])
{
    map<int,int> max;
    for(int i = 0; i < r; i++)
    {
        int j = 0;
        while(a[i][j] != 1 && j < c)
        {
            j++;
        }
        if(a[i][j] == 1)
        {
            max[i] = c - j;
        }
    }
    int maxrow = -1;
    for(int i = 0; i < c; i++)
    {
        if(max[i] > maxrow)
        {
            maxrow = i+1;
        }
    }
    cout<<"\n Row with max 1's is : "<<maxrow;
}

int main()
{
    int a[r][c] = {{0,0,1,1},{0,0,0,1},{0,1,1,1},{0,0,1,1}};
    max1(a);
}
