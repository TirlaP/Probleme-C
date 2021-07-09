#include <stdio.h>
#include <stdlib.h>

void prim(int n);

int main()
{
    int nr;
    printf("Numarul pe care doriti sa il verificati este: ");
    scanf("%d", &nr);

    prim(nr);

    return 0;
}

void prim(int n)
{
    int prim = 1;

    if (n < 2)
        prim = 0;
    else
        for (int d = 2; d * d <= n; d++)
        {
            if (n % d == 0)
            {
                prim = 0;
                break;
            }
        }

    if (prim == 1)
        printf("\nNumarul %d este prim.\n", n);
    else
        printf("\nNumarul %d nu este prim.\n", n);
}
