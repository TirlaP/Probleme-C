#include <stdio.h>
#include <stdlib.h>

#define N 10

int * citireSir(int *n);
int conversieBinar(int *n);

int main()
{
    int n;
    scanf("%d", &n);

    int *binar = conversieBinar(&n);

    for (int i = n - 1; i >= 0; i--)
        printf("%d", binar[i]);

    return 0;
}

int * citireSir(int *n)
{
    printf("Introdu numarul de elemente al sirului: ");
    scanf("%d", n);

    int *sir = (int *) malloc((*n) * sizeof(int));

    for (int i = 0; i < (*n); i++)
    {
        *(sir + i) = i;
    }
    return sir;
}

int conversieBinar(int *n)
{
    int *rez, *temp, i = 0, marime;
    marime = N;

    rez = (int *) malloc(marime * sizeof(int));
    while (*n)
    {
        if (i == marime)
        {
            marime *= 2;
            temp = realloc(rez, marime * sizeof(int));

            if (temp != NULL)
                rez = temp;
            else
                break;
        }
        rez[i] = (*n) % 2;
        (*n) /= 2;
        i++;
    }
    *n = i;
    return rez;
}

