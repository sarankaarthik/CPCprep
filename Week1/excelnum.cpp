#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
    char str[50];
    int n = 701;
    int i = 0;
    while (n > 0)
    {
        int rem = n % 26;
        if (rem == 0)
        {
            str[i++] = 'Z';
            n = (n / 26) - 1;
        }
        else
        {
            str[i++] = (rem - 1) + 'A';
            n = n / 26;
        }
    }
    str[i] = '\0';
    reverse(str, str + strlen(str));
    for(int i = 0; i < strlen(str); i++)
        cout<<str[i];
}
