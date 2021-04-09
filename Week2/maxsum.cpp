#include <iostream>
#include <vector>

using namespace std;

void maxsum(vector<int> a)
{
    int in = a[0];
    int ex = 0;
    int ex1;
    int i;
    
    for (i = 1; i < a.size(); i++)
    {
        if(in > ex)
            ex1 = in;
        else
            ex1 = ex;
        in = ex + a[i];
        ex = ex1;
    }
    if(in > ex)
        cout<<in;
    else
        cout<<ex;
    }
    
    int main()
    {
    vector<int> a{1,2,3,4,5,6};
    maxsum(a);
    }
