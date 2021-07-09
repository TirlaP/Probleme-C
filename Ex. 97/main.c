#include <stdio.h>
#include <stdlib.h>

/*
    Se dă un număr natural n şi un tablou unidimensional cu 3*n
    elemente, numere naturale cu cel mult 4 cifre. Tabloul este
    împărţit în trei zone, cu câte n elemente: prima zonă conţine
    primele n elemente din tablou, a doua zonă conţine următoarele
    n elemente din tablou, restul elementelor fiind în zona a
    treia.

    Se cere interschimbarea primulul element par (dacă există) al
    zonei unu cu ultimul element impar (dacă există) al zonei trei.
    În cazul în care unul dintre elementele care urmează a fi
    interschimbate nu există, tabloul rămâne nemodificat.
*/

int main(int argc, char *argv[])
{
    int n, v[303], primPar = 0, ultimImp = 0;

    FILE *in = fopen(argv[1], "rt");

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }
    fscanf(in, "%d", &n);

    for (int i = 1; i <= n; i++)
    {
        fscanf(in, "%d", &v[i]);
        if (v[i] % 2 == 0 && primPar == 0)
            primPar = i;
    }

    for (int i = n + 1; i <= 2 * n; i++)
    {
        fscanf(in, "%d", &v[i]);
    }

    for (int i = 2 * n + 1; i <= 3 * n; i++)
    {
        fscanf(in, "%d", &v[i]);
        if (v[i] % 2 == 1)
            ultimImp = i;
    }

    fclose(in);

    if ( primPar != 0 && ultimImp != 0)
    {
        int aux = v[primPar];
        v[primPar] = v[ultimImp];
        v[ultimImp] = aux;
    }

    FILE *out = fopen(argv[2], "wt");
    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= 3 * n; i++)
        fprintf(out, "%d ", v[i]);

    fclose(out);

    return 0;
}
