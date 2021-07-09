#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Să se scrie un program care sa administreze un parc de
    automobile. Informaţiile relative la un automobil sunt:
    numărul de locuri, puterea (în cai putere), marca, culoarea,
    anul fabricaţiei maşinii

    a) se vor citi informatiile relative la cele n automobile din
    parcul de autoturisme. Se vor afisa doar acele automobilele
    care au 5 locuri;

    b) sa se ordoneze crescator dupa putere automobilele – se vor
    afisa datele ordonate;

    c) sa se scrie o functie care afiseaza toate automobilele
    fabricate într-un anumit an dat ca parametru.
*/

typedef struct
{
    int locuri, caiPutere, anFabricatie;
    char marca[20], culoare[20];

} automobil;

int main()
{
    int n, anCautat;
    automobil masini[10];
    citire(masini, &n);
    afisare(masini, n);

    ordonarePutere(masini, n);

    printf("\nIntrodu anul de fabricatie pe care il cauti: ");
    scanf("%d", &anCautat);

    afisareAn(masini, n, anCautat);
    return 0;
}

void citire(automobil v[], int *n)
{
    printf("Introdu numarul de automobile: ");
    scanf("%d", n);

    printf("\n\n");

    for (int i = 0; i < *n; i++)
    {
        printf("Introdu date automobil %d:\n", i + 1);

        printf("\t-Numar de locuri: ");
        scanf("%d", &v[i].locuri);
        printf("\t-Cai putere: ");
        scanf("%d", &v[i].caiPutere);
        printf("\t-Marca: ");
        scanf("%s", &v[i].marca);
        printf("\t-Culoare: ");
        scanf("%s", &v[i].culoare);
        printf("\t-An fabricatie: ");
        scanf("%d", &v[i].anFabricatie);
    }
}

void afisare(automobil v[], int n)
{
    printf("\nAutomobilele cu 5 locuri sunt: \n");

    for(int i = 0; i < n; i++)
    {
        if (v[i].locuri == 5)
        {
            printf("  Automobilul %d\n", i + 1);
            printf("\t-Marca: %s\n", v[i].marca);
            printf("\t-Cai putere: %d\n", v[i].caiPutere);
            printf("\t-Culoarea: %s\n", v[i].culoare);
            printf("\t-Anul fabricatiei: %d\n\n", v[i].anFabricatie);
        }
    }
}

void ordonarePutere(automobil v[], int n)
{
    int ok;
    do
    {
        ok = 1;
        for(int i = 0; i < n - 1; i++)
        {
            if (v[i].caiPutere > v[i+1].caiPutere)
            {
                swapIntegers(&v[i].locuri, &v[i+1].locuri);
                swapIntegers(&v[i].caiPutere, &v[i+1].caiPutere);
                swapIntegers(&v[i].anFabricatie, &v[i+1].anFabricatie);
                swapStrings(&v[i].marca, &v[i+1].marca);
                swapStrings(&v[i].culoare, &v[i+1].culoare);
                ok = 0;
            }
        }
    }
    while (ok == 0);

    printf("\nAutomobilele dupa ordonare sunt: \n");

    for(int i = 0; i < n; i++)
    {
        printf("  Automobilul %d\n", i + 1);
        printf("\t-Marca: %s\n", v[i].marca);
        printf("\t-Locuri: %d\n", v[i].locuri);
        printf("\t-Cai putere: %d\n", v[i].caiPutere);
        printf("\t-Culoarea: %s\n", v[i].culoare);
        printf("\t-Anul fabricatiei: %d\n\n", v[i].anFabricatie);
    }
}

void afisareAn(automobil v[], int n, int anCautat)
{
    int cnt = 0;


    printf("\nAutomobilele fabricate in anul %d sunt:\n\n", anCautat);
    for(int i = 0; i < n; i++)
    {
        if (v[i].anFabricatie == anCautat)
        {
            cnt++;
            printf("  Automobilul %d\n", i + 1);
            printf("\t-Marca: %s\n", v[i].marca);
            printf("\t-Locuri: %d\n", v[i].locuri);
            printf("\t-Cai putere: %d\n", v[i].caiPutere);
            printf("\t-Culoarea: %s\n", v[i].culoare);
            printf("\t-Anul fabricatiei: %d\n\n", v[i].anFabricatie);
        }
    }
    if (cnt == 0)
        printf("\tNu s-au gasit vehicule fabricate in anul %d in reprezentanta noastra. Ne pare rau!\n\n", anCautat);
}

void swapIntegers(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swapStrings(char str1[], char str2[])
{
    char aux[] = "";
    strcpy(aux, str1);
    strcpy(str1, str2);
    strcpy(str2, aux);
}
/*
Exemplu:

    3
    5
    155
    Fiat
    Rosu
    2003
    5
    140
    Golf
    Gri
    2002
    4
    137
    Ventura
    Negru
    2001
*/
