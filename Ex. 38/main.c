#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256
#define SEPARATORS " ,."

/**
    Folosind funcţia strtok, citiţi un şir de caractere, apoi un
    cuvânt şi afişaţi pe ecran numărul de apariţii al cuvântului
    în şir.
*/

void citireSir(char *str, char *cuv);
void afisareStrtok(char *str, char *cuv);

int main()
{
    char *str = malloc(N * sizeof(char));
    char *cuv = malloc(20 * sizeof(char));

    citireSir(str, cuv);
    afisareStrtok(str, cuv);

    return 0;
}

void citireSir(char *str, char *cuv)
{
    printf("Introdu sirul dorit: ");
    gets(str);
    printf("\nIntrodu cuvantul cautat: ");
    gets(cuv);
}

void afisareStrtok(char *str, char *cuv)
{
    char *p;
    int count = 0;

    p = strtok(str, SEPARATORS);
    while(p)
    {
        if (strcmp(cuv, p) == 0)
        {
            count++;
        }

        p = strtok(NULL, SEPARATORS);
    }

    printf("Cuvantul \"%s\" apare de %d ori in sirul dat.\n", cuv, count);
}
