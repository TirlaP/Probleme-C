#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    Swap(&a, &b);

    printf("%d, %d", a, b);

    return 0;
}
