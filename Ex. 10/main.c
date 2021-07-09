#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define INCR 100
#define esc 27

/**
    În exemplul următor se citeşte un număr necunoscut de valori
  întregi într-un vector extensibil:

*/
int main()
{
    int n, i, m;
    float nr, *v, *temp;

    n = INCR;
    i = 0;

    v = malloc(n * sizeof(float));
    if (v == NULL)
    {
        /// Nu s-a reusit alocarea...
        printf("Could no allocate v. \n");
        exit(0);
    }

    printf("\n Continutul vectorului: \n");


    /*  /// Citire din fisier
    while (scanf("%f", &x) != EOF)
    {
        if (i == n)                // Daca este necesar...
        {
            n = n + INCR;              // ... creste dimensiune vector
            tmp = realloc(v, n * sizeof(float));
            if (tmp != NULL)
            {
                // Daca s-a reusit alocarea pentru noua zona de memorie
                v = tmp;
            }
            else
            {
                // Daca nu s-a reusit alocarea
                break;
            }
        }

        v[i++] = x;      // Memorare in vector numar citit
    }

    */

    char ch;
    /// Cat timp nu am apasat tasta esc pentru a iesi din program
    do
    {
        ch = getch();
        if (ch == esc)
        {
            break;
        }
        else
        {
            scanf("%f", &nr);
            if (i == n)           /// Daca este necesar...
            {
                n = n + INCR;       ///... creste dimensiune vector
                temp = realloc(v, n * sizeof(float));
                if (temp != NULL)
                {
                    /// Daca s-a reusit alocarea pentru noua zona de memorie
                    v = temp;
                }
                else
                {
                    /// Daca nu s-a reusit alocarea
                    break;
                }
            }
            /// Memorare in vector numar citit
            v[i++] = nr;
        }

    }
    while (1);

    m = i;

    printf("\n Elementele din vector sunt: \n ");
    for (i = 0; i < m; i++)
    {
        printf("%3.2f ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}
