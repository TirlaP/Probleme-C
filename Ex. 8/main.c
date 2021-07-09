#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d ", &d);

    char *str = malloc(30);           ///Aloca memorie pentru 30 de caractere
    int *a = malloc(n * sizeof(int)); /// Aloca memorie pentru n numere intregi

    /// Aloca memorie pentru n numere intregi si initializeaza zona cu 0
    int *vect = calloc(n, sizeof(int));

    /// Algoritmul de mai sus este echivalent cu cel de mai jos
    /// (doar ca mai rapid)

    int i;
    int *vect1 = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        vect1[i] = 0;
        /// *(vect1 + i) = 0;
    }

    int *aux;
    aux = realloc(vect, 2 * n * sizeof(int)); /// Dublare dimensiune anterioara(n)
    if (aux != NULL)
        vect = aux;
    else
        {
            ;//prelucrare in caz de eroare
        }

    return 0;
}
