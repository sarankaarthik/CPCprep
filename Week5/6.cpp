#include <iostream>
#include <vector>
#include <map>

using namespace std;

void fixed(vector<int> a)
{
    int low = 0;
    int high = a.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(a[mid] > mid)
            high = mid - 1;
        else if(a[mid] < mid)
            low = mid + 1;
        else
        {
            cout<<mid;
            return;
        }
    }
    cout<<"-1";
    return;
}

int main()
{
    vector<int> a{-1,1,3,7,9,10};
    fixed(a);
}
