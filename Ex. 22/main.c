#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Scrieți funcția Trim care primește ca parametru un șir de
    caractere s, elimină eventualele spații de la începutul și
    sfârșitul șirului și returnează tot prin intermediul lui s
    sirul de caractere rezultat.
*/

void Trim(char sir[])
{
    char aux[256] = "";
    int i, n = strlen(sir), inceput = 0, sfarsit, k = 0;

    for (i = 0; i < n; i++)
    {
        if (sir[i] != ' ' && inceput == 0)
        {
            inceput = i;
        }

        if (sir[i] != ' ')
            sfarsit = i;
    }

    for (i = inceput; i <= sfarsit; i++)
        aux[k++] = sir[i];

    strcpy(sir, aux);
}

int main()
{
    char sir[256];
    gets(sir);

    Trim(sir);
    printf("%s", sir);

    return 0;
}
