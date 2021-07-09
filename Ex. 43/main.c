#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/* Numarul maxim de personalitati cu care poate lucra
 programul. */
#define MAX 100
/* Lungimea maxima a numelui. */
#define MAX_LEN 50

struct personalitate {
    char nume[MAX_LEN];
    int nastere;
    int moarte;
};


int main()
{
    struct personalitate pers[MAX];

    int n, i, an;

    printf("Introdu numarul de personalitati: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Personalitatea %d\n", i + 1);
        printf("Introdu numele acesteia: ");
        gets(pers[i].nume);
        gets(pers[i].nume);

        /*
        fgets(pers[i].nume, MAX_LEN, stdin);
        fgets(pers[i].nume, MAX_LEN, stdin);

        pers[i].nume[strlen(pers[i].nume) - 1] = 0;
        */
        printf("Introdu anul nasterii: ");
        scanf("%d", &pers[i].nastere);
        printf("Introdu anul mortii: ");
        scanf("%d", &pers[i].moarte);
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%s (%d - %d)\n", pers[i].nume, pers[i].nastere,
               pers[i].moarte);
    }

    printf("\nIntrodu anul pentru care doresti cautarea: ");
    scanf("%d", &an);
    printf("In anul %d au fost in viata:\n", an);
    for (i = 0; i < n; i++)
    {
        if (pers[i].nastere <= an && pers[i].moarte >= an)
        {
            printf("%s\n", pers[i].nume);
        }
    }

   return 0;
}





