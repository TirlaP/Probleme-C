#include <stdio.h>
#include <stdlib.h>

/*
    Se dă o matrice cu elemente numere naturale. Să se determine
    cea mai mică valoare de pe fiecare linie, iar dintre acestea
    să se determine valoarea maximă.
*/

int main(int argc, char *argv[])
{
    int n, m, mat[24][24], minim, maxim = 0;

    FILE *in = fopen(argv[1], "rt");

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }
    fscanf(in, "%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fscanf(in, "%d", &mat[i][j]);

    fclose(in);
    FILE *out = fopen(argv[2], "wt");
    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= n; i++)
    {
        minim = 1000;
        for (int j = 1; j <= m; j++)
        {
            if (mat[i][j] < minim)
                minim = mat[i][j];
        }
        if (minim > maxim)
            maxim = minim;
    }

    fprintf(out, "%d", maxim);
    return 0;
}
