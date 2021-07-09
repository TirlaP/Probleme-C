#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256
#define SEPARATORS " .,"
/**
    Folosind funcţia strtok, citiţi un şir de caractere şi afişaţi
    pe ecran cuvintele sale constituente.
*/

void citireSir(char *str);
void afisareStrtok(char *str);

int main()
{
    char *str;
    str = malloc(N * sizeof(char));
    citireSir(str);
    afisareStrtok(str);

    return 0;
}

void citireSir(char *str)
{
    printf("Introdu sirul dorit spre afisare: ");
    gets(str);
}

void afisareStrtok(char *str)
{
    char *p;

    printf("Cuvintele sirului sunt:\n");

    p = strtok(str, SEPARATORS);
    while(p)
    {
        printf("%s\n", p);
        p = strtok(NULL, SEPARATORS);
    }
}
