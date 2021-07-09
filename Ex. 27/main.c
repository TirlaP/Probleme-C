#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Funcția primește ca parametru un șir s format din cuvinte separate
    prin câte un spațiu. Cuvintele sunt formate doar din litere mici.
    Funcția va returna, tot prin intermediul parametrului s, cuvintele
    în ordine inversă, separate tot prin câte un spațiu.
*/

void ReverseWords(char s[]);

int main()
{
    char sir[800000];

    gets(sir);
    ReverseWords(sir);

    printf("%s", sir);

    return 0;
}

void ReverseWords(char sir[])
{
    int n = 0;

    char *cuv = strtok(sir, " ");
    char matCuvinte[100][100];

    while (cuv)
    {
        strcpy(matCuvinte[n++], cuv);
        cuv = strtok(NULL, " ");
    }

    int k = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < strlen(matCuvinte[i]); j++)
            sir[k++] = matCuvinte[i][j];

        if (i != 0)
            sir[k++] = ' ';
    }

}
