#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
 
bool sub(vector<int> a)
{
    unordered_set<int> sumSet;
    int sum = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
 
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
 
int main()
{
    vector<int> a{ -3, 2, 3, 1, 6 };
    cout<<sub(a);
    return 0;
}
