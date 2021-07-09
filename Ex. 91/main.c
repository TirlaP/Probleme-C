#include <stdio.h>
#include <stdlib.h>
/*
    Numim secvență încadrată a unui șir de numere naturale un
    subșir al acestuia, format din termeni aflați pe poziții
    consecutive în șirul dat, subșir care începe și se termină cu
    aceeași valoare. Lungimea secvenței este egală cu numărul de
    termeni ai acesteia.

    Să se determine secvențele încadrate dintr-un șir, care au
    lungimea maximă.
*/

int poz[10], lung[10];

int main (int argc, char *argv[])
{
    int cif, cnt = 0, lungMax = 0;

    FILE *in = fopen(argv[1], "rt");

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }

    while (!feof(in))
    {
        fscanf(in, "%d", &cif);
        cnt++;
        if (poz[cif] == 0)
        {
            poz[cif] = cnt;
            lung[cif] = 1;
        }
        else
            lung[cif] = cnt - poz[cif] + 1;
    }

    for (cif = 0; cif < 10; cif++)
        if (lung[cif] > lungMax)
            lungMax = lung[cif];

    fclose(in);
    FILE *out = fopen(argv[2], "wt");

     if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }

    fprintf(out, "%d\n", lungMax);

    for (cif = 0; cif < 10; cif++)
        if (lung[cif] == lungMax)
            fprintf(out, "%d ", cif);

    fclose(out);
    return 0;
}
