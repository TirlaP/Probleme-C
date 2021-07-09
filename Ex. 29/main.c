#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int extrageCuvant(char dest[], char sir[], char separ[], int poz);

int main()
{
    char sir[1000], destinatie[100], separatori[10];
    gets(sir);
    gets(separatori);

    int poz;
    scanf("%d", &poz);

    printf("%d", extrageCuvant(destinatie, sir, separatori, poz));


    return 0;
}

int extrageCuvant(char dest[], char sir[], char separ[], int poz)
{
    int cnt = 0, inceput = 0, lung = 0;
    dest[0] = '\0';

    while (sir[inceput] == ' ')
        inceput++;

    for (int i = inceput; i < strlen(sir); i++)
    {
        if (cnt == poz)
        {
            for (int j = i; sir[j] != ' ' || sir[j]; j++)
            {
                dest[lung++] = sir[j];
            }
            return 1;
        }
        else
        {
            if (sir[i] == ' ')
                cnt++;
        }
    }
    return 0;
}
