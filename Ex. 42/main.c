#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Cititi si afisati un vector de cuvinte doar cu ajutorul
    functiilor.
*/

char **citireSir(int n);
void afisare(char **sir, int n);

int main()
{
    char **vector = 0;

    int n, i;
    printf("Introduceti nr de cuvinte: ");
    scanf("%d", &n);

    vector = citireSir(n);

    afisare(vector, n);

    for (i = 0; i < n; i++)
    {
        free(vector[i]);
        vector[i] = 0;
    }

    free(vector);

    return 0;
}

char **citireSir(int n)
{
    char **sir = 0;
    int i;
    sir = (char **) malloc(n * sizeof(char));
    if (sir == 0)
    {
        printf("Eroare la alocare!\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        sir[i] = (char *) malloc(256 * sizeof(char));
        if (sir[i] == 0)
        {
        printf("Eroare la alocare!\n");
        exit(EXIT_FAILURE);
        }
    }

    printf("\nIntroduceti cuvintele dorite:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", *(sir + i));
    }

    return sir;
}

void afisare(char ** sir, int n)
{
    int i;

    printf("\nCuvintele introduse sunt:\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\n", *(sir + i));
    }
}


