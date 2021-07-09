#include <stdio.h>
#include <stdlib.h>

#define N 30
/**
    Citire a unui şir, caracter cu caracter pana la întâlnirea
    caracterului '-':
*/

int main()
{
    char str[N], c;
    int n = 0;

    do
    {
        scanf("%c", &c);
        if (c == '-')
        {
            break;
        }
        str[n++] = c;
    }while(1);

    str[n] = '\0'; // setam terminatorul de șir
    puts(str);

    return 0;
}
