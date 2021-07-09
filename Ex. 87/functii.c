#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu()
{
    printf("-------------------------------< M E N I U >-------------------");
    printf("\n\n\t1 - citeste sir");
    printf("\n\t2 - afisare sir");
    printf("\n\t3 - determinate lungime traseu parcurs");
    printf("\n\t4 - afisare puncte (x,y) in plan 2D");
    printf("\n\t5 - determinare numar panglici de uscat si de apa");
    printf("\n\t6 - calculam temperatura medie pe traseu");
    printf("\n\t7 - afisare informatii despre autor");
    printf("\n\t8 - terminare program");
    printf("\n--------------------------------< alege optiune>--------\n");
}

void infoAutor()
{
    printf("\nProgramul a fost creat de ...\n");
}

void afisareSir(char s[])
{
    printf("Sirul citit este: %s", s);
}

void afisareSirLitere(char s[])
{
    int n = strlen(s);


    for (int i = 0; i < n; i++)
    {
//        if (strchr("qwertyuiopasdfghjklzxcvbnm", s[i]))
//        {
//            printf("%c", s[i] - 32);
//        }
//        else if (strchr("QWERTYUIOPASDFGHJKLZXCVBNM" ,s[i] ))
//        {
//            printf("%c", s[i] + 32);
//        }
//        else
//            printf("%c", s[i]);

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            printf("%c", s[i] + 32);
        }
        else
            printf("%c", s[i]);

    }
}

void afisareLitereMici(char s[])
{
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("_");
        }
        else
            printf("%c", s[i]);
    }
}

void afisareLungime(char s[])
{
    int n = strlen(s);
    int k = n;

    printf("Lungimea sirului este %d\n", n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            k--;
        }
    }
    printf("Lungimea sirului fara spatii este %d\n", k);
    printf("Numarul de spatii este %d\n", n - k);

}

void afisareCuvinteInvers(char s[])
{
    int n = strlen(s), cntCuv = 0, cntLitere = 0;
    char cuv[10][20];
    for (int i = 0; i < 10; i++)
    {
        strcpy(cuv[i], "");
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            cuv[cntCuv][cntLitere] = s[i];
            cntLitere++;
        }
        else cntCuv++;
    }
    cntCuv++;

    for (int i = cntCuv; i >= 0; i--)
    {
        printf("%s\n", cuv[i]);
    }
}










