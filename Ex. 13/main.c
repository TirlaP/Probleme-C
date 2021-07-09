#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, m;
    float nr, *vect;

    n = 4;
    i = 0;

    vect = malloc(n * sizeof(float));

    while(scanf("%f", &nr) != EOF)
    {
        if (i == n)
        {
            n = n * 2;
            vect = realloc(vect, n * sizeof(float));
        }
        vect[i++] = nr;
    }

    m = i;

    for (i = 0; i < m; i++)
    {
        printf("%.2f ", vect[i]);
    }
    printf("\n");

    free(vect);

    return 0;
}
