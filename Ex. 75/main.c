#include <stdio.h>
#include <stdlib.h>

/// Elementele sirului vor fi aleatorii.

int * citireSir(int *n);
void sortareCresc(int n, int *sir);
void sortareDescr(int n, int *sir);
void swap (int *a, int *b);

int main()
{
    int n;
    int *sir;

    sir = citireSir(&n);
    printf("\nElementele sirului inainte de sortare sunt: \n");
    afisare(n, sir);

    sortareDescr(n, sir);

    printf("\nElementele sirului dupa sortare sunt: \n");
    afisare(n, sir);

    return 0;
}

int * citireSir(int *n)
{
    printf("Introdu numarul de elemente al sirului: ");
    scanf("%d", n);
    int *sir = (int *) malloc((*n) * sizeof(int));

    for (int i = 0; i < *n; i++)
    {
        sir[i] = rand();
    }
    return(sir);
}

void sortareCresc(int n, int *sir)
{
    int sortat;
    do
    {
        sortat = 1;
        for (int i = 0; i < n - 1; i++)
            if (*(sir + i) > *(sir + i + 1))
            {
               swap((sir + i), (sir + i + 1));
               sortat = 0;
            }
    }while (sortat == 0);
}


void sortareDescr(int n, int *sir)
{
    int sortat;
    do
    {
        sortat = 1;
        for (int i = 0; i < n - 1; i++)
            if (*(sir + i) < *(sir + i + 1))
            {
               swap((sir + i), (sir + i + 1));
               sortat = 0;
            }
    }while (sortat == 0);
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void afisare(int n, int *sir)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(sir + i));
    printf("\n");
}

