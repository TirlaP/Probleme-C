#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void verifNrPalindrom(int nr);
void verifSirPalindrom(int sir[], int n);
void verifCuvantPalindrom(char *str);

int main()
{
    char *sir[256];
    gets(sir);

    verifCuvantPalindrom(&sir);
    return 0;
}

void verifNrPalindrom(int nr)
{
    int ogl = 0, aux = nr;
    while (aux)
    {
        ogl = ogl * 10 + aux % 10;
        aux /= 10;
    }
    if (ogl == nr)
        printf("Numarul dat este palindrom.");
    else
        printf("Numarul dat nu este palindrom.");
}

int verifSirPalindrom(int sir[], int n)
{
    int i = 0, j = n - 1, ok = 1;

    while (i <= j)
    {
        if (sir[i] != sir[j])
            {
                ok = 0;
                break;
            }
        i++;
        j--;
    }

    if (ok == 1)
        printf("Sirul dat este palindrom.");
    else
        printf("Sirul dat nu este palindrom.");
}

void verifCuvantPalindrom(char *str)
{
    int ok = 1;

    int n = strlen(str);

    for (int i = 0, j = n - 1; i < n / 2 && ok == 1; i++, j--)
    {
        while (str[i] == ' ')
            i++;
        while (str[j] == ' ')
            j--;

        if (str[i] != str[j])
            ok = 0;
    }

    if (ok == 1)
        printf("Propozitia este palindrom.");
    else
        printf("Propozitia nu este palindrom.");
}
