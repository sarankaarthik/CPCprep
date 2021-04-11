#include <iostream>

using namespace std;

void displayMatrix(unsigned int const *p, unsigned int r, unsigned int c) 
{ 
    unsigned int row, col; 
    for (row = 0; row < r; row++) 
    { 
        for (col = 0; col < c; col++) 
            cout << * (p + row * c + col) << " "; 
        cout << "\n"; 
    } 
    cout <<endl; 
} 
  
void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col) 
{ 
    unsigned int r, c; 
    for (r = 0; r < row; r++) 
    { 
        for (c = 0; c < col; c++) 
        { 
            *(pD + c * row + (row - r - 1)) = *(pS + r * col + c); 
        } 
    } 
} 
  
int main() 
{ 
      
    unsigned int image[][4] = {{1, 2, 3, 4}, 
                               {5, 6, 7, 8}, 
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}; 
    unsigned int *pSource; 
    unsigned int *pDestination; 
    unsigned int m, n; 

    m = 4, n = 4, pSource = (unsigned int *)image; 
    pDestination = (unsigned int *)malloc(sizeof(int) * m * n);
    rotate(pSource, pDestination, m, n); 
    displayMatrix(pDestination, n, m); 
} 
