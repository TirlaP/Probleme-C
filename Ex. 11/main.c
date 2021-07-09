#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/// Matrice alocata dinamic

/**

    *Notaţia a[i][j] este interpretată astfel pentru o matrice alocată dinamic:

    - a[i] conţine un pointer (o adresă b)
    - b[j] sau b+j conţine întregul din poziţia j a vectorului cu adresa b.

*/
void afisareMatrice(int **a, int nL, int nC);
int **newMat(int nl, int nc);

int main()
{

    int i, j, nrLinii, nrCol;

    printf("Numarul de linii este: ");
    scanf("%d", &nrLinii);

    printf("Numarul de coloane este: ");
    scanf("%d", &nrCol);

    int **mat = newMat(nrLinii, nrCol);

    if (nrLinii == nrCol)
        /// Completare diagonala matrice unitate
        for (i = 0; i < nrLinii; i++)
            mat[i][i] = 1; /// a[i][j] = 0 pentru i != j

    /// Afisare matrice
    afisareMatrice(mat, nrLinii, nrCol);

    for (i = 0; i < nrLinii; i++)
        free(mat[i]);

    free(mat);

    return 0;
}

int **newMat(int nl, int nc)
{
    int i;
    /**
        * In cele ce urmeaza presupunem ca toate apelurile de alocare
        * de memorie nu vor esua.
    */

    /// Alocare pentru vector de pointeri
    int **mat = malloc(nl * sizeof(int *));

    for (i = 0; i < nl; i++)
    {
        /// Alocare pentru o linie si initializarea cu 0
        mat[i] = calloc(nc, sizeof(int));
    }

    return mat;
}

void afisareMatrice(int **a, int nL, int nC)
{
    printf("\n");
    for (int i = 0; i < nL; i++)
    {
        for (int j = 0; j < nC; j++)
        {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
}
