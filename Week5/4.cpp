#include <iostream>
#include <vector>
#include <map>

using namespace std;

void ceil(vector<int> a, int x)
{
    int low = 0;
    int high = a.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(a[mid] > x)
            high = mid - 1;
        else if(a[mid] < x)
            low = mid + 1;
        else
        {
            cout<<a[mid];
            return;
        }
    }
    cout<<a[high + 1];
    return;
}

int main()
{
    vector<int> a{1,2,6,7,9,10};
    int x;
    cin>>x;
    ceil(a,x);
}
