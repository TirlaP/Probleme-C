#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int x, y, z;
    char temp[10];

} coordonate;

void printMenu()
{
    printf("-------------------------------< M E N I U >-------------------");
    printf("\n\n\tC - citeste sir");
    printf("\n\tA - afisare sir");
    printf("\n\tL - determinate lungime traseu parcurs");
    printf("\n\tV - afisare puncte (x,y) in plan 2D");
    printf("\n\tN - determinare numar panglici de uscat si de apa");
    printf("\n\tT - calculam temperatura medie pe traseu");
    printf("\n\tI - afisare informatii despre autor");
    printf("\n\tE - terminare program");
    printf("\n--------------------------------< alege optiune>--------\n");
}

void selectMenu()
{
    coordonate puncte[100];
    int cnt;

    do
    {
        system("cls");
        printMenu();
        switch(getch())
        {
        case 'c':
        case 'C':
            citireSir(puncte, &cnt);
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        case 'a':
        case 'A':
            afisareSir(puncte, cnt);
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        case 'l':
        case 'L':
            lungimeTraseu(puncte, cnt);
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        case 'v':
        case 'V':
            afisarePuncte(puncte, cnt);
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        case 'n':
        case 'N':
            nrPanglici(puncte, cnt);
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        case 't':
        case 'T':
            //calculTemp();
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        case 'i':
        case 'I':
            infoAutor();
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        case 'e':
        case 'E':
            exit(1);
            break;
        default:
            printf("\nOptiunea nu este valida! Incercati din nou");
            printf("\n\nPress  any key to continue!\n");
            getch();
            break;
        }
    }while(1);
}

void citireSir(coordonate puncte[], int *cnt)
{
    int ok = 1, k = 0;
    FILE *in = fopen("input.txt", "rt");

    if (in == NULL)
    {
        fprintf(stderr, "Eroare: Nu s-a putut deschide fisierul");
        exit(-1);
    }
    int a, b, c;
    char temp[10];
    fscanf(in, "%d %d %d", &puncte[k].x, &puncte[k].y, &puncte[k].z);
    fgets(puncte[k].temp, 10, in);
    k++;

    while(ok == 1)
    {
        fscanf(in, "%d %d %d", &puncte[k].x, &puncte[k].y, &puncte[k].z);
        fgets(puncte[k].temp, 10, in);
        if (puncte[0].x == puncte[k].x && puncte[0].y == puncte[k].y && puncte[0].z == puncte[k].z)
            ok = 0;
        k++;
    }
    k--;
    *cnt = k;

    fclose(in);

    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d %s", puncte[i].x, puncte[i].y, puncte[i].z, puncte[i].temp);
    }
}
//290,1NULL
//
//290.1
//c = 290.1 - 273.15
//
//-


void afisareSir(coordonate puncte[], int n)
{
    float aux;
    char aux1[10];


    for (int i = 0; i < n; i++)
    {
        int lung = strlen(puncte[i].temp);

        if (strchr(puncte[i].temp, 'K'))
        {
            puncte[i].temp[lung - 1] = NULL; // '\0'
            aux = atof(puncte[i].temp);
            aux = aux - 273.15;
            sprintf(aux1, "%.1f", aux);
            strcpy(puncte[i].temp, aux1);
            printf("%d %d %d %sC", puncte[i].x, puncte[i].y, puncte[i].z, puncte[i].temp);
        }
        else if (strchr(puncte[i].temp, '-'))
        {
            strcpy(puncte[i].temp, puncte[i - 1].temp);
            printf("%d %d %d %s\n", puncte[i].x, puncte[i].y, puncte[i].z, puncte[i].temp);
        }
            else
        printf("%d %d %d %s", puncte[i].x, puncte[i].y, puncte[i].z, puncte[i].temp);
    }
}

void lungimeTraseu(coordonate puncte[], int n)
{
    float s = 0;
    for (int i = 1; i < n; i++)
    {
        s += sqrt(pow((puncte[i].x - puncte[i - 1].x), 2) + pow((puncte[i].y - puncte[i - 1].y), 2));
    }
    s += sqrt(pow((puncte[n - 1].x - puncte[0].x), 2) + pow((puncte[n - 1].y - puncte[0].y), 2));
    printf("%.2f", s);
}

void afisarePuncte(coordonate puncte[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (puncte[i].x > 0 && puncte[i].y > 0)
        {

            printf("(%d, %d) cadr, I,", puncte[i].x, puncte[i].y);
        }
        else
        if (puncte[i].x < 0 && puncte[i].y > 0)
        {
            printf("(%d, %d) cadr, II,", puncte[i].x, puncte[i].y);
        }
        else
        if (puncte[i].x < 0 && puncte[i].y < 0)
        {
            printf("(%d, %d) cadr, III,", puncte[i].x, puncte[i].y);
        }
        else
        if (puncte[i].x > 0 && puncte[i].y < 0)
        {
            printf("(%d, %d) cadr, IV,", puncte[i].x, puncte[i].y);
        }
        else if (puncte[i].x == 0 && puncte[i].y < 0)
        {
            printf("(%d, %d) axa Y,", puncte[i].x, puncte[i].y);
        }
        else
            if (puncte[i].x > 0 && puncte[i].y == 0)
        {
            printf("(%d, %d) axa X,", puncte[i].x, puncte[i].y);
        }
        else if (puncte[i].x > 0 && puncte[i].y == 0)
        {
            printf("(%d, %d) origine,", puncte[i].x, puncte[i].y);
        }
    }
}

void nrPanglici(coordonate puncte[], int n)
{
    int cntUscat = 0, cntApa = 0;
    int cadr1, cadr2, cadr3, cadr4;
    cadr1 = cadr2 = cadr3 = cadr4 = 0;

    for (int i = 0; i < n; i++)
    {
        if (puncte[i].x > 0 && puncte[i].y > 0)
        {
            if (cadr1 == 0)
                {
                    cntUscat++;
                    cadr1 = 1;
                }
        }
        else
        if (puncte[i].x < 0 && puncte[i].y > 0)
        {
            if (cadr2 == 0)
                {
                    cntUscat++;
                    cadr2 = 1;
                }
        }
        else
        if (puncte[i].x < 0 && puncte[i].y < 0)
        {
            if (cadr3 == 0)
                {
                    cntApa++;
                    cadr3 = 1;
                }
        }
        else
        if (puncte[i].x > 0 && puncte[i].y < 0)
        {
            if (cadr4 == 0)
                {
                    cntApa++;
                    cadr4 = 1;
                }
        }
    }
    printf("Numarul de panglici de uscat = %d iar de apa = %d", cntUscat, cntApa);
}



void infoAutor()
{
    printf("Autorul acestui program este ...");
}

