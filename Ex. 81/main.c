#include <stdio.h>
#include <stdlib.h>

/**
    Enumerati avantajele si dezavantajele listelor simple fata de
    masive alocate static/dinamic. Dati exemple de cazuri in care
    este mai eficenta flosirea listelor si cazuri in care este
    mai eficienta folosirea vectorilor.
*/

int main()
{
    int mat[100][100], vect[1000], lin = 0, cnt = 0, col, nr;

    printf("Introdu numarul de coloane al matricei tale: ");
    scanf("%d", &col);

    printf("Introdu numerele din matrice pana la valoarea 0:\n");

    int n = 0;
    do
    {
        scanf("%d", &nr);
        vect[n++] = nr;
    }
    while(nr != 0);

    n--;

    lin = n / col;

    if (n % col != 0)
        lin++;

    int k = 0;

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat[i][j] = vect[k++];
        }
    }

    for (int i = 0; i < lin; i++)
    {
        if (i == lin - 1 && n % col != 0)
        {
            for (int j = 0; j < n % col; j++)
            {
                printf("%d ", mat[i][j]);
            }
        }
        else
            for (int j = 0; j < col; j++)
            {
                printf("%d ", mat[i][j]);
            }

        printf("\n");
    }
    return 0;
}
