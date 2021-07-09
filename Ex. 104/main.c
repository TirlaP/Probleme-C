#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, m, mat[10][10];
    FILE *in = fopen(argv[1], "rt");

    if (in = NULL)
    {
        printf("Eroare la deschiderea fisierului!");
        exit(-1);
    }

    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(in, "%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

printf("%d", mat[i][n - i - 1]);
