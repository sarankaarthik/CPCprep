#include <iostream>
#include <vector>

using namespace std;

void eq(vector<int> a)
{
    int n = a.size();
    int sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        sum2 += a[i];
    }
    int sum1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum1 != sum2)
        {
            sum1 += a[i];
            sum2 -= a[i];
        }
        else
        {
            cout<<i+1;
            return;
        }
    }
}

int main()
{
    vector<int> a{2,1,5,0,4,3,1};
    eq(a);
}
