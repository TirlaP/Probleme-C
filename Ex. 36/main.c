#include <stdio.h>
#include <stdlib.h>

#define N 256

/**
    Să se determine dacă o propozitie este palindromă. O propozitie
     este palindromă daca citită de la prima literă pană la ultima
     are aceeasi succesiune ca citită de la ultima literă până la
     prima. Nu conteaza dacă sunt litere mici sau mari.

    Exemplu: ele fac cafele
*/

void citireSir(char *str);
void verifPal(char *str);

int main()
{
    char *str;
    str = malloc(N * sizeof(char));
    citireSir(str);
    verifPal(str);

    return 0;
}

void citireSir(char *str)
{
    printf("Introdu sirul dorit: ");
    gets(str);
}

void verifPal(char *str)
{
    int ok = 1;

    int n = strlen(str);

    for (int i = 0, j = n - 1; i < n / 2 && ok == 1; i++, j--)
    {
        while (str[i] == ' ')
            i++;

        while (str[j] == ' ')
            j--;

        if (str[i] != str[j])
            ok = 0;
    }

    if (ok == 1)
        printf("Sirul este palindrom.");
    else
        printf("Sirul nu este palindrom.");
}


