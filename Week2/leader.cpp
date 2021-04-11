#include <iostream>
#include <vector>

using namespace std;
 
void leader(vector<int> a)
{
    int n = a.size();
    int max =  a[n-1];
    cout << max << " ";
    for (int i = n-2; i >= 0; i--)
    {
        if (max <= a[i])
        {          
            max = a[i];
            cout << max << " ";
        }
    }   
}

int main()
{
    vector<int> a{1, 15, 12, 14, 7, 8, 2};
    leader(a);
}   
