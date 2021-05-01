#include <iostream>
#include <vector>
#include <map>

using namespace std;

void majority(vector<int> a, int x)
{
    int low = 0;
    int high = a.size() - 1;
    int n = a.size();
    int i;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if(mid == 0 || x > a[mid - 1] && a[mid] == x)
        {
            i = mid;
            break;
        }
        else if(x > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (((i + n / 2) <= (n - 1)) && a[i + n / 2] == x)
        cout<<"true";
    else
        cout<<"false";
}

int main()
{
    vector<int> a{1,2,2,3,3,3,3,4,5};
    int x;
    cin>>x;
    majority(a,x);
}
