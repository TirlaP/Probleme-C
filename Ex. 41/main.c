#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Cititi si afisati un sir de caractere cu ajutorul functiilor.
*/

void  citireSir(char *sir);
void  afisare(char *sir);

int main()
{
    char *vector = malloc(256 * sizeof(char));
    citireSir(vector);
    afisare(vector);


    return 0;
}

void  citireSir(char *sir)
{
    printf("Introdu sirul dorit: ");
    gets(sir);
}

void  afisare(char *sir)
{
    printf("\nSirul introdus de catre tine este: %s\n", sir);
}
