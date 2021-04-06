#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

void sum(int a[], int n, int sum)
{
    bool found = false;
    for(int i = 0; i < n-1; i++)
    {
        unordered_set<int> hash;
        for(int j = i + 1; j < n; j++)
        {
            int x = sum - (a[i] + a[j]);
            if(hash.find(x) != hash.end())
            {
                cout<<a[i]<<" "<<a[j]<<" "<<x<<endl;;
                found = true;
            }
            else
            {
                hash.insert(a[j]);
            }
        }
    }
    if(found == false)
    {
        cout<<"\n No Triplet";
    }
}

int main()
{
    int a[] = {1, 2, 6, -2, 0, 5};
    int n = sizeof(a)/sizeof(a[0]);
    int sum;
    cin>>sum;
    sum(a,n,sum);
}
