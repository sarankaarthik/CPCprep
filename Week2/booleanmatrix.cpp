#include <iostream>
#include <cstring>
 
using namespace std;
#define R 3
#define C 4
 
void modifyMatrix(bool mat[R][C])
{
    bool row[R];
    bool col[C];
 
    int i, j;
     
    memset(row, 0, sizeof(row));

    memset(col, 0, sizeof(col));
 
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (mat[i][j] == 1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
 
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if ( row[i] == 1 || col[j] == 1 )
            {
                mat[i][j] = 1;
            }
        }
    }
}
 

int main()
{
    bool mat[R][C] = { {1, 0, 1, 1},
                       {0, 0, 0, 1},
                       {0, 0, 0, 0}};
 
    modifyMatrix(mat);
 
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}
