#include <iostream>
#include <vector>

using namespace std;

int arraysum(vector<int> a, int sum)
{
    int x = a[0], start = 0, i;
    int n = a.size();
    for (i = 1; i <= n; i++) 
    {
        while (x > sum && start < i - 1)
        {
            x = x - a[start];
            start++;
        }
        if (x == sum)
        {
            cout<<start<<" "<<i - 1;
            return 1;
        }
 
        if (i < n)
            x = x + a[i];
    }
    cout << "No subarray found";
    return 0;
}
 
int main()
{
    vector<int> a{1,2,6,3,4,5};
    int sum = 11;
    arraysum(a, sum);
    return 0;
}
