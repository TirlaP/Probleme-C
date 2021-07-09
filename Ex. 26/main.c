#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int litera(char ch);
void Alphanum(char sir[], char cuv[][21], int *n, int num[], int *m);

int main()
{
    int n, m, num[100];
    char sir[256], cuv[100][21];

    gets(sir);

    Alphanum(sir, cuv, &n, num, &m);

    return 0;
}

int litera(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    return 0;
}

void Alphanum(char sir[], char cuv[][21], int *n, int num[], int *m)
{
    *n = 0;
    *m = 0;

    char *p = strtok(sir, " ");

    while (p)
    {
        if (litera(p[0]))
            strcpy(cuv[(*n)++], p);
        else
            num[(*m)++] = atoi(p);

        p = strtok(NULL, " ");
    }

    printf("Cuvintele din sir sunt: \n");
    for (int i = 0; i < *n; i++)
    {
        printf("%s\n", cuv[i]);
    }

    printf("\nNumerele din sir sunt: \n");
    for (int i = 0; i < *m; i++)
    {
        printf("%d\n", num[i]);
    }
}
