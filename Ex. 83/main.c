#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

int main()
{
    char input_filename[] = "date.in";

    FILE *in = fopen(input_filename, "rt");

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", input_filename);
        return -1;
    }

    int n, v[NMAX], i;

    fscanf(in, "%d", &n);

    for(i = 0; i < n; i++)
    {
        fscanf(in, "%d", &v[i]);
    }

    fclose(in);

    for (i = 0; i < n; i++)
    {
        v[i] <<= 1;
    }

    char output_filename[] = "date.out";

    FILE *out = fopen(output_filename, "wt");

    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", output_filename);
        return -1;
    }

    fprintf(out, "Numarul de elemente este: %d\n", n);

    for(int i = 0; i < n; i++)
    {
        fprintf(out, "%d ", v[i]);
    }
    fprintf(out, "\n");

    fclose(out);

    return 0;
}
