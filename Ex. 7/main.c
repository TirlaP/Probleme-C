#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int *p;
    int n, i;
    printf("\n Cate valori intregi doriti sa cititi? ");
    scanf("%d", &n);
    p = (int *) malloc(n * sizeof(int));

    if (p == NULL)
    {
        printf("\n Nu se pot aloca %d octeti!", n*sizeof(int));
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nElementul %d : ", i);
        scanf("%d", &p[i]);
        /// scanf("%d", p+i);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d, ", *(p + i));
        /// printf("%d, ", p[i]);
    }
    printf("\b\b.\n");
    free(p);

    return 0;
}
