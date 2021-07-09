#include <stdio.h>
#include <stdlib.h>

#include "functii.h"

int f(float nr0, float nr1, float nr2, int k, int cnt)
{
    if (cnt < k)
        return f(nr1, nr2, 0.3 * nr2 + 0.4 * nr1 + 0.3 * nr0, k, ++cnt);
    else
        return nr2;
}

int main()
{
    selectMenu();

    FILE *in = fopen("gigel.in", "rb");

    int rez;
    unsigned char c;

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Nu am putut deschide fisierul");
        exit(EXIT_FAILURE);
    }

    fread(&c, sizeof(c), 2, in);
        printf("%d", c);

    fclose(in);

    return 0;
}

//a = 2, b = 3, c = 4;
//
//2 + 3 + 4 + 2 = 11 / 4 = 2
//
//2.00000
//
//a = 0, b = 1, c = 2;
//
//a = 1 + 1 + (-1);
//    ->b = 0, c = 1, b = -1
//
//c = (c -= 1, c + 1);
//
//c = 0, c = 1
//
//a = 1
//
//if (a > 2)
//    b = b++;
//else
//    b = ++b;
//
//b = 0
//
//a = 1, b = 0, c = 1
