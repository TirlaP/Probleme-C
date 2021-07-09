#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Creare/afisare vector de pointeri la siruri alocate dinamic
    Lucrul cu fisiere

    */

int readstr(char *vp[], FILE *in);
void sort(char *vp[], int n);
void printstr(char *vp[], int n, FILE *out);


int main()
{

    char input_filename[] = "date.in";

    FILE *in = fopen(input_filename, "rt");
    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", input_filename);
        return -1;
    }

    int n;
    char *vp[1000];

    n = readstr(vp, in); // citire siruri si creare vector
    fclose(in);
    sort(vp, n); // ordonare vector

    char output_filename[] = "date.out";

    FILE *out = fopen(output_filename, "wt");
    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", output_filename);
        return -1;
    }

    printstr(vp, n, out); // afisare siruri

    fclose(out);

    return 0;
}

/// Citire siruri si creare vector de pointeri

int readstr(char *vp[], FILE *in)
{
    int n = 0;
    char *p, sir[80];

    while (fscanf(in, "%s", sir) != EOF)
    {
        p = malloc(strlen(sir) + 1);
        strcpy(p, sir);
        vp[n] = p;
        ++n;
    }
    return n;
}

/// Afisare siruri reunite in vector de pointeri

void printstr(char *vp[], int n, FILE *out)
{
    int i;

    for (i = 0; i < n; i++)
    {
        fprintf(out, "%s\n", vp[i]);
    }
}

/// Ordonare vector de pointeri la siruri

void sort(char *vp[], int n)
{
    int i, j;
    char *temp;

    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (strcmp(vp[i], vp[i + 1]) > 0)
            {
                temp = vp[i];
                vp[i] = vp[i + 1];
                vp[i + 1] = temp;
            }
        }
    }
}


