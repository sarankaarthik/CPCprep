#include<iostream>
#include<map>
#include<vector>

using namespace std;

void miss(vector<int> a, int n)
{
    map<int, int> occ;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
        {
            occ[a[i]]++;
        }
    }
    for(int i = 1; i <= n+1; i++)
    {
        if(occ[i] == 0)
        {
            cout<<i;
            return;
        }
    }

}

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    miss(a,n);
}
