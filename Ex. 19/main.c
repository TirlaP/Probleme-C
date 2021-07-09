#include <stdio.h>
#include <stdlib.h>

/**
     Să se scrie un program care citeşte de la tastatură un număr pozitiv
     n împreună cu alt număr pozitiv max. Programul va aloca apoi
     dinamic un vector de întregi de n elemente, pe care îl va
     iniţializa cu numere aleatoare în intervalul [0..max-1].
     Sortaţi vectorul, folosind metoda preferată, afişându-i conţinutul
     atât înainte, cât şi după ce sortarea a avut loc.

*/
void sort(int v[], int n);
void swap(int *a, int *b);
void afisareSir(int v[], int n);

int main()
{
    int n, maxx;
    int *sir;
    scanf("%d%d", &n, &maxx);

    sir = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        sir[i] = rand() % (maxx - 1);


    printf("\n Inainte de sortare: \n");
    afisareSir(sir, n);
    sort(sir, n);
    printf("\n Dupa de sortare: \n");
    afisareSir(sir, n);
    free(sir);
    return 0;
}

void sort(int v[], int n)
{
    int sortat;

    do {
        sortat = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i+ 1])
            {
                swap(&v[i], &v[i + 1]);
                sortat = 0;
            }
        }

    }while (sortat == 0);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void afisareSir(int v[], int n)
{
    printf(" Elementele sirului sunt: \n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}


