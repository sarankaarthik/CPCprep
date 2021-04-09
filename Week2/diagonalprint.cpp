#include<iostream>
#include<vector>

using namespace std;

#define r 3
#define c 4

void diagonalprint(int a[r][c])
{
    int sum = r + c - 1;
    vector<vector<int>> ans(sum);
 
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ans[i + j].push_back(a[j][i]);
        }
    }
 
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int a[r][c] = {{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12}};
    diagonalprint(a);
}
