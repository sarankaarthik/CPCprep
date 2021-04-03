#include <iostream>
#include <vector>
#include <map>

using namespace std;

int search(vector<int> a, int x)
{
    int n = a.size();
    map<int,int> hash;
    for(int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        int need = x - a[i];
        if(hash[need] != 0)
        {
            cout<<"\n The two numbers whose sum add upto "<<x<<" are : "<<a[i]<<" and "<<need;
            return 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> a = {1, 6, 3, 4, 5};
    cout<<"\n Enter number : ";
    int x;
    cin>>x;
    int flag = search(a,x);
    if(flag == 0)
    {
        cout<<"\n There are no such numbers";
    }
}
