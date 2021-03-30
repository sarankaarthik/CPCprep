#include<iostream>
#include<map>
#include<vector>

using namespace std;

void missing(vector<int> a, int n)
{
    map<int, int> miss;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
        {
            miss[a[i]]++;
        }
    }
    for(int i = 1; i <= n+1; i++)
    {
        if(miss[i] == 0)
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
    missing(a,n);
}
