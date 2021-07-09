#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 10;
    int ***p1;
    int **p2;
    int *p3;


    p3 = &i;
    p2 = &p3;
    p1 = &p2;

    printf(" ***p1 = %d SI **p2 = %d SI *p3 = %d", **p1, **p2, *p3);

    return 0;
}
