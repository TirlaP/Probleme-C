#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

/**
    Să presupunem că avem următorul fișier care pe prima linie conține
    un număr natural nenul n, iar pe a doua linie se află n numere
    întregi reprezentând elementele unui vector. Se cere citirea
    vectorului, dublarea fiecarui element, apoi salvarea rezultatelor
    în fișierul “gigel.out”.
*/

int main()
{
    char input_filename[] = "gigel.in";

    // deschidere fisier de intrare pentru
    // citire (r) in modul text (t)
    FILE *in = fopen(input_filename, "rt");

    // verific daca fisierul a fost deschis cu succes
    // altfel opresc executia (in cazul acestei probleme)
    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", input_filename);
        return -1;
    }

    int n, v[NMAX], i;

    fscanf(in, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(in, "%d", &v[i]);
    }

    // deoarece stiu sigur ca nu mai am nimic de citit
    // pot inchide fisierul de intrare
    fclose(in);

    // dublez elementele din vector
    for (i = 0; i < n; i++)
    {
        v[i] <<= 1;
    }

    char output_filename[] = "gigel.out";
    // deschid pentru scriere (w) in modul text(t)
    FILE *out = fopen(output_filename, "wt");

    // verific daca fisierul a fost deschis cu succes
    // altfel opresc executia (in cazul acestei probleme)

    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open file %s", output_filename);
        return -1;
    }

    // scriu n si vectorul in fisier
    fprintf(out, "Numarul de elemente este: %d\n", n);
    for (i = 0; i < n; i++)
    {
        fprintf(out, "%d ", v[i]);
    }
    fprintf(out, "\n");

    // inchid fisierul de iesire
    fclose(out);

    return 0;
}
