#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

/**
    Folosind funcţiile din <string.h> înlocuiţi într-un text dat o
    secventă de caractere cu altă secvenţă de caractere, date la
    intrare.
*/

void citireSir(char *str, char *secventa, int *inceput);
void inlocuireSecventa(char *str, char *secventa, int inceput);

int main()
{
    char *str = malloc(N * sizeof(char));
    char *secventa = malloc(30 * sizeof(char));
    int inceput;

    citireSir(str, secventa, &inceput);
    printf("%s %s %d\n", str, secventa, inceput);

    memmove(str + inceput, secventa, strlen(secventa));

    printf("%s\n", str);
    return 0;
}

void citireSir(char *str, char *secventa, int *inceput)
{
    int ok;
    printf("Introdu sirul dorit: ");
    gets(str);

    printf("\nIntrodu secventa dorita spre inlocuire: ");
    do
    {
        ok = 1;
        gets(secventa);
        if (strlen(secventa) > strlen(str))
        {
            printf("\nSecventa data este prea mare. Introdu alta secventa: ");
            ok = 0;
        }
    }while (ok == 0);


    int lungSir = strlen(str), lungSecv = strlen(secventa);

    do
    {
        ok = 1;
        printf("\nIntrodu inceputul zonei de inlocuit: ");
        scanf("%d", inceput);
        if (lungSecv + *inceput > lungSir)
        {
            printf("\nZona introdusa este prea mare, numarul maxim este %d."
                   " Introdu alta zona de inceput.",
                    lungSir - lungSecv);
            ok = 0;
        }
    }while (ok == 0);


}

void inlocuireSecventa(char *str, char *secventa, int inceput)
{

}


