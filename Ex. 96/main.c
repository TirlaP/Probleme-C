#include <stdio.h>
#include <stdlib.h>

/*
    Se dă o matrice cu elemente numere întregi. Să se determine
    media aritmetică a elementelor strict pozitive din matrice,
    care sunt situate sub diagonala principală.
*/

/// i > j
int main(int argc, char *argv[])
{
    float ma = 0;
    int n, mat[21][21], cnt = 0;

    FILE *in = fopen(argv[1], "rt");

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }
    fscanf(in, "%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fscanf(in, "%d", &mat[i][j]);

    fclose(in);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i > j)
                if (mat[i][j] > 0)
            {
                ma += mat[i][j];
                cnt++;
            }

    FILE *out = fopen(argv[2], "wt");
    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }


    ma = ma / cnt;
    if (cnt == 0)
        fprintf(out, "NU EXISTA");
    else
    fprintf(out, "%.3f", ma);

    fclose(out);
    return 0;
}
