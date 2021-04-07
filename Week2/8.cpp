#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

bool compare(int x, int y)
{
    return abs(x) < abs(y);
}

void zero(vector<int> a)
{
    int n = a.size();
    int x,y;
    sort(a.begin(),a.end(),compare);
    int min = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        if(abs(a[i-1] + a[i]) <= min)
        {
            min = abs(a[i-1] + a[i]);
            x = i-1;
            y = i;
        }
    }
    cout<<a[x]<<" "<<a[y];
}

int main()
{
    vector<int> a{-1,5,-2,6,4,-7};
    zero(a);
}
