#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n, i;
    int *vect;

    printf("\n Lungimea vectorului este : ");
    scanf("%d", &n);

    vect = calloc(n, sizeof(int));
    printf("\n Componentele vectorului: \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", vect + i);
    }

    printf("\n Elementele vectorului sunt: \n ");

    for (i = 0; i < n; i++)
    {
        printf("%d, ", *(vect + i));
    }

    free(vect);

    printf("\b\b.\n");
    return 0;
}
