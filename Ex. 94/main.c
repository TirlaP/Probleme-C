#include <stdio.h>
#include <stdlib.h>

/*
    Se dă o matrice cu elemente numere naturale, care conţine doar
    valorile {0,1,2}. Să se determine numerele de ordine ale
    coloanelor pentru care produsul elementelor este maxim.
*/

int m,n,a[101][101];

int p2(int j)
{
    int i,p=0;
    for (i=1; i<=m; i++)
        if(a[i][j]==2)
            p++;
        else if(a[i][j]==0)
            return 0;
    if(p==0)
        return 1;
    else
        return p+1;
}

void citire(int argc, char *argv[])
{
    int i, j, ma;

    FILE *in = fopen(argv[1], "rt");

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }
    fscanf(in, "%d %d", &n, &m);

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            fscanf(in, "%d", &a[i][j]);

    fclose(in);
    FILE *out = fopen(argv[2], "wt");
    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }

    ma = 0;
    for(j = 1; j <= n; j++)
        if(p2(j) > ma)
            ma = p2(j);
    for(j = 1; j <= n; j++)
        if(p2(j) == ma)
            fprintf(out, "%d ", j);
}

int main(int argc, int *argv[])
{
    citire(argc, argv);
    return 0;
}
