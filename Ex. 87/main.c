#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"

/*
    1.Citeste un sir de caractere si il afiseaza
    2.Afiseaza sirul initial inlocuind literele mari cu cele mici si invers
    3.Afiseaza sirul initial inlocuind orice caracter cu litera mica cu _
    4.Afiseaza lungimea sirului ,lungimea sirului fara spatii si numarul de spatii
    5.Afiseaza fiecare caracter insotit de numarul sau de aparitii in sir
    6.Afiseaza cuvintele sirului in ordine inversa
    7.Citeste sirul "cuvant1 = cuvant2" si inlocuieste in sir primul cuvant(daca exista) cu al doilea cuvant
    8.Informatii autor program
    9.parasire program

*/
int main()
{
    char sir[256];

    FILE *in = fopen("date.in", "rt");

    if (in == NULL)
    {
        printf("Eroare la deschiderea fisierului.");
        exit(-1);
    }

    do
    {
        system("cls");
        printMenu();

        switch(getch())
        {
        case '1':
            printf("\nIntrodu sirul de caractere dorit:\n");
            fgets(sir, 256, in);
            afisareSir(sir);
            printf("Press any key to continue!");
            getch();
            break;
        case '2':
            afisareSirLitere(sir);
            printf("Press any key to continue!");
            getch();
            break;
        case '3':
            afisareLitereMici(sir);
            printf("Press any key to continue!");
            getch();
            break;
        case '4':
            afisareLungime(sir);
            printf("Press any key to continue!");
            getch();
            break;
        case '5':
            printf("Press any key to continue!");
            getch();
            break;
        case '6':
            printf("Press any key to continue!");
            getch();
            break;
        case '7':
            afisareCuvinteInvers(sir);
            printf("Press any key to continue!");
            getch();
            break;
        case '8':
            infoAutor();
            break;
        case '9':
            printf("Ati ales sa parasiti programul!");
            exit(1);
            break;
        }

    }while(1);


    return 0;
}


