#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char mat[50][50];
    citire(mat, argv);

    return 0;
}

void citire(char mat [][50], char *argv[])
{
    FILE *in = fopen(argv[1], "rt");

    int cnt = 0, j = 0;

    char rez;
    rez = fgetc(in);
    while (rez != '.')
    {
        mat[cnt][j] = rez;
        if (rez == '\n')
        {
            mat[cnt][j + 1] = NULL;
            cnt++;
            j = -1;

        }
        j++;
        rez = fgetc(in);
    }
    if (rez == '.')
    {
        mat[cnt][j + 1] = NULL;
        cnt++;

    }

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < strlen(mat[i]); j++)
            if (strchr("aeiou", mat[i][j]))
            {
                for (int k = j; k < strlen(mat[i]); k++)
                {
                    mat[i][k] = mat[i][k + 1];
                }
            }
    }

    for (int i = 0; i < cnt; i++)
        printf("%s", mat + i);
}

