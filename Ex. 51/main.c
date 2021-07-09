#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    char sir[256][10];
} numere;

void printMenu();
void citireSir(char fisier[], char *sir[100][10]);
void afisareSir(numere matrice, int n);
void afisareVirgula(numere matrice, int n);
void afisarrNrCuv(numere matrice, int cuvRand[], int randuri);
void decode(numere matrice, int n, char decodificat[]);
void encode();
void info();

int main()
{
    FILE *fp;
    fp = fopen("date.txt", "r");

    if(fp == NULL)
    {
        perror("Nu s-a putut deschide fisierul!");
        exit(EXIT_FAILURE);
    }

    int i, n = 0, count = 1, cuv = 0, m = 0, randuri = 0;

    /// Folosim o matrice de cuvinte pentru citire
    numere matrice, codificat;
    int decodificat[256], cuvRand[256];

    char read, text[1000];

    do
    {
        printMenu();
        switch(getch())
        {
        case 'c':
            do
            {
                /// citim prima data litera cu litera din fisier
                read = fgetc(fp);
                /// copiem cuvantul citit pe randul actual din matrice
                if (read != ' ')
                {
                    matrice.sir[n][m] = read;
                    m++;
                }

                if (read == '\n')
                {
                    cuv++;
                    cuvRand[randuri] = cuv;
                    randuri++;
                    cuv = 0;
                }
                else if (read == ' ')
                {
                    cuv++;
                    matrice.sir[n][m] = '\0';
                    n++;
                    m = 0;
                }
                else if (read == '.')
                {
                    cuv++;
                    cuvRand[randuri] = cuv;
                    randuri++;
                    matrice.sir[n][m] = '\0';
                    n++;
                    cuv = 0;
                }

                /// daca am ajuns la finalul fisierului sau daca
                /// am gasit '.' iesim din citire
                if (feof(fp) || read == '.')
                {
                    break;
                }
            }
            while(1);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 'a':
            afisareSir(matrice, n);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 'l':
            printf("\nNumarul de randuri este: %d", randuri);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 'v':
            afisareVirgula(matrice, n);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 'n':
            afisarrNrCuv(matrice, cuvRand, randuri);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 'd':
            decode(matrice, n, decodificat);
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 'e':
            encode();
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 'i':
            info();
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        case 't':
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("\nOptiune inexistenta!");
            printf("\nPress any key to continue!\n\n");
            getch();
            break;
        }
    }
    while(1);

    fclose(fp);

    return 0;
}

void printMenu()
{
    system("cls");
    printf("\t######## Aplicatie ########\n\n");

    printf("\tC - citeste un text terminat cu caracterul \".\"\n");
    printf("\tA - afiseaza textul citit\n");
    printf("\tL - Calculeaza si afiseaza numarul de randuri din text\n");
    printf("\tV - Afiseaza sirul citit\n");
    printf("\tN - afiseaza numarul cuvintelor (numerelor)\n");
    printf("\tD - Decodifica mesajul primit\n");
    printf("\tE - Va citi un text si il va codifica\n");
    printf("\tI - Afiseaza informatii despre autorul programului\n");
    printf("\tT - Terminare program\n");

    printf("\n Introduceti optiunea dorita: \n");

}

void afisareSir(numere matrice, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", matrice.sir[i]);
    }
}

void afisareVirgula(numere matrice, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%s, ", matrice.sir[i]);
    }
    printf("%s", matrice.sir[n - 1]);
}

void afisarrNrCuv(numere matrice, int cuvRand[], int randuri)
{
    printf("\nNr. Cuvinte (coduri/numere): ");
    for (int i = 0; i < randuri - 1; i++)
    {
        printf("%d, ", cuvRand[i]);
    }
    printf("%d", cuvRand[randuri - 1]);
}

void decode(numere matrice, int n, char decodificat[])
{
    int count = 1;
    for(int i = 0; i < n; i++)
    {

        if (strchr(matrice.sir[i], '\n'))
        {
            if ((count - 1) % 3 == 0)
                sscanf(matrice.sir[i], "%o", &decodificat[i]);
            if ((count - 2) % 3 == 0)
                sscanf(matrice.sir[i], "%d", &decodificat[i]);
            if ((count - 3) % 3 == 0)
                sscanf(matrice.sir[i], "%x", &decodificat[i]);

            decodificat[++i] = '\n';

        }
        else if ((count - 1) % 3 == 0)
            sscanf(matrice.sir[i], "%o", &decodificat[i]);
        if ((count - 2) % 3 == 0)
            sscanf(matrice.sir[i], "%d", &decodificat[i]);
        if ((count - 3) % 3 == 0)
            sscanf(matrice.sir[i], "%x", &decodificat[i]);

        count++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c", decodificat[i]);
    }
}

void encode()
{
    int count = 1;
    char text[1000];

    printf("\nIntrodu un text: ");
    fflush(stdin);
    gets(text);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (count == 1)
            printf( "%o ", text[i]);
        else if (count == 2)
            printf("%d ", text[i]);
        else if (count == 3)
        {
            printf("%x ", text[i]);
            count = 0;
        }
        count++;
    }
}
void info()
{
    printf("Creatorul programului se numeste Tirla Petru si este din grupa 3112A");
}

