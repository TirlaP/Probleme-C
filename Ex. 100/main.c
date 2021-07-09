#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\Florin\Desktop\Aplicatii C\Calculator simplu\functii.h"

/*
    Se dă o matrice reprezentând o zonă dintr-un ocean ce
    conține un iceberg; valorile egale cu 1 fac parte din
    iceberg, iar cele egale cu 0 reprezintă apă.

    Se știe că icebergul este înconjurat de apa (nu există nici o
    valoare de 1 pe marginea matricei) și că într-un interval de
    timp se topesc toate zonele icebergului care au cel puțin
    doua laturi vecine cu apa.

    Determinați și afișați cate intervale de timp sunt necesare ca
    icebergul să se topească în întregime. De asemenea, afișați
    pentru fiecare interval de timp câte poziții de gheață are
    icebergul la începutul intervalului.
*/

int vecini_apa (int i, int j, int ice[][32])
{
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    int va = 0, k, ii, jj;

    for (k = 0; k < 4; k++)
    {
        ii = i + dx[k];
        jj = j + dy[k];
        if (ice[ii][jj] == 0)
            va++;
    }
    return va;
}

int main()
{
    systemColor();

    int n, i, j, ice[32][32], nrGheata = 0;
    scanf("%d", &n);


    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &ice[i][j]);
            if (ice[i][j] == 1)
                nrGheata++;
        }

    int parcurgeri = 0, poz[101];
    while (nrGheata != 0)
    {
        parcurgeri++;
        poz[parcurgeri] = nrGheata;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                if (ice[i][j] == 1)
                    /// verificam daca elementul 1 are cel putin doi
                    /// vecini egali cu 0
                    if (vecini_apa(i, j, ice) >= 2)
                    {
                        /// daca da, punem pe pozitia sa -1
                        ice[i][j] = -1;
                        nrGheata--;
                    }
            }
        /// parcurgem din nou matricea si punem pe pozitiile cu -1, 0
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if(ice[i][j] == -1)
                    ice[i][j] = 0;
    }


    printf("%d\n", parcurgeri);
    for (i = 1; i <= parcurgeri; i++)
        printf("%d\n", poz[i]);

    return 0;
}
