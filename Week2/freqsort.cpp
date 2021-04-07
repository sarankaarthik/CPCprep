#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, pair<int, int> > p, pair<int, pair<int, int> > p1)
{
    if (p.second.second != p1.second.second)
        return (p.second.second > p1.second.second);
    else
        return (p.second.first < p1.second.first);
}

void freqsort(vector<int> a)
{
    int n = a.size();
    map<int, pair<int,int> > freq;
    for(int i = 0; i < n; i++)
    {
        if(freq.find(a[i]) != freq.end())
            freq[a[i]].second++;
        else
            freq[a[i]] = make_pair(i,1);
    }
    vector <pair <int, pair <int,int> > > b;
    for(auto i = freq.begin(); i != freq.end(); i++)
    {
        b.push_back(make_pair(i->first,i->second));
    }
    sort(b.begin(),b.end(),comp);
    for(int i = 0; i < b.size(); i++)
    {
        int count = b[i].second.second;
        while (count--)
            cout << b[i].first << " ";
    }
}

int main()
{
    vector<int> a{-1,1,-1,2,3,3,3,4,10};
    freqsort(a);
}
