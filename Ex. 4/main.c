#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[100], i;
    int *p1;

    for (i = 0; i < 100; i++)
        data[i] = i;

    p1 = data;
    for (; *p1 < sizeof(data); ++p1)
        printf("%d ", *p1);

    printf("\n Marimea sirului este de %d biti.",sizeof(data));

    return 0;
}
