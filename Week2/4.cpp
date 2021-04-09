#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
void findTriplets(vector<int> a, int sum)
{
    int i;
    int n = a.size();
    sort(a.begin(),a.end());
    bool flag = false;
 
    for (i = 0; i < n - 2; i++)
    {
        if (i == 0 || a[i] > a[i - 1])
        {
            int start = i + 1;
            int end = n - 1;

            int target = sum - a[i];
 
            while (start < end)
            {
                if (start > i + 1
                    && a[start] == a[start - 1])
                {
                    start++;
                    continue;
                }
                if (end < n - 1 && a[end] == a[end + 1])
                {
                    end--;
                    continue;
                }
                if (target == a[start] + a[end])
                {
                    cout<<a[i]<<" "<<a[start]<<" "<<a[end]<<" "<<endl;
                    flag = true;
                    start++;
                    end--;
                }
                else if (target > (a[start] + a[end]))
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
    if (flag == false)
    {
        cout << "No Such Triplets Exits"
             << "\n";
    }
}

int main()
{
    vector<int> a{12, -3, 9, 1, -6, 7};
    int x;
    cin>>x;
    findTriplets(a, x);
    return 0;
}
