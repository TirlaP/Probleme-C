#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringSearch(char str1[], char str2[]);

int main()
{
    char sir1[1001], sir2[1001];

    printf("Introdu sirul in care vrei sa cauti: ");
    gets(sir1);
    printf("\nIntrodu sirul pe care vrei sa il cauti: ");
    gets(sir2);
    stringSearch(sir1, sir2);

    return 0;
}

void stringSearch(char str1[], char str2[])
{
    int i = 0, j = 0, lung = strlen(str2), cnt = 0;

    while (str1[i] != '\0')
    {
        if (str1[i] == str2[j])
        {
            while (str1[i] == str2[j] && str1[i] != '\0')
            {
                i++;
                j++;
            }
        }

        if (lung == j && (str1[i] == ' ' || str1[i] == '\0'))
        {
            cnt++;
        }
        else
        {
            while (str1[i] != ' ')
            {
                i++;
                if (str1[i] == '\0')
                    break;
            }
        }
        i++;
        j = 0;
    }

    if (cnt > 0)
        printf("'%s' apare de %d ori in primul sir.\n", str2, cnt);
    else
        printf("'%s' nu apare deloc in primul sir.\n", str2);
}
