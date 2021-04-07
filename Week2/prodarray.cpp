#include<iostream>
#include<vector>

using namespace std;

vector<int> prodarray(vector<int> a)
{
    int n = a.size();
    vector<int> b(n);
    fill(b.begin(),b.end(),1);
    int temp = 1;
    for(int i = 0; i < n; i++)
    {
        b[i] *= temp;
        temp *= a[i];
    }
    temp = 1;
    for(int i = n-1; i > -1; i--)
    {
        b[i] *= temp;
        temp *= a[i];
    }
    return b;
}

int main()
{
    vector<int> a{1,2,3,4,5,6};
    vector<int> b = prodarray(a);
    int n = b.size();
    for(int i = 0; i < n; i++)
        cout<<b[i]<<" ";
}
