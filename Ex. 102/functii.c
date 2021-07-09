#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu1()
{
    printf("----------< MENIU >----------");
    printf("\n\n op1");
    printf("\n\n op2");
    printf("\n\n op3");
    printf("\n\n op4");
    printf("\n\n op5");
    printf("\n\n op6");
    printf("\n\n op7");
    printf("\n\n op8");
    printf("\n\n op9");
    printf("\n---------< Alege optiunea: >----------\n");
}

void info_autor()
{
    printf("\n Programul a fost realizat de: ...");
}

void afisareSir(char sir[], char *argv[])
{
    FILE *out = fopen(argv[2], "wt");

    fprintf(out, "Sirul citit este: %s", sir);
}
