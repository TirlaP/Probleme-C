#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Matrice alocată dinamic (cu dimensiuni necunoscute la execuţie)
    Plus lucrul cu fisiere
    */
int main()
{
    char input_filename[] = "date.in";

    FILE *in = fopen(input_filename, "rt");
    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", input_filename);
        return -1;
    }

    int n, i, j;
    int **mat;

    fscanf(in, "%d", &n);

    mat = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        mat[i] = calloc(n, sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            fscanf(in, "%d", &mat[i][j]);
        }
    }
    fclose(in);

    char output_filename[] = "date.out";

    FILE *out = fopen(output_filename, "wt");
    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", output_filename);
        return -1;
    }

    fprintf(out, "Matricea este de %dX%d\n\n", n, n);

    fprintf(out, "Elementele matricei sunt: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(out, "%d ", mat[i][j]);
        }
        fprintf(out, "\n");
    }
    fclose(out);

    return 0;
}
