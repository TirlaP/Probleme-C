#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

#define NMAX 100

int main(int argc, char *argv[])
{

//    int a = 5, *b, *v, *aux;
//
//    v = malloc(sizeof(int), NMAX);
//
//    for (int i = 0; i < 100; i++)
//    {
//        v[i] = i;
//    }
//
//    int lungime = NMAX * 2;
//    aux = calloc(sizeof(int), lungime);
//
//    for (int i = 0; i < lungime; i++)
//    {
//        aux[i] = i;
//    }
//
//    v = aux;
//
//    for (int i = 0; i < lungime; i++)
//        printf("%d ", v[i]);
//_______________________________________
//    int a, b, aux;
//    a = 2, b = 5;
//
//    swap(&a, &b);
//    printf("%d %d", a, b);

    int n;
    float sir[100];
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);

    FILE *in = fopen(argv[1], "rt");

    if (in == NULL)
    {
        printf("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    fscanf(in, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%f", &sir[i]);
    }

    fclose(in);

    FILE *out = fopen(argv[2], "wt");

    if (out == NULL)
    {
        printf("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    fprintf(out, "Elementele din sir sunt: \n");

    for (int i = 0; i < n; i++)
    {
        fprintf(out, "%.2f ", sir[i]);
    }

    fclose(out);

    //citire(&n, sir);
    //afisare(n, sir);

    return 0;
}


