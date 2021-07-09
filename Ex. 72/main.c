#include <stdio.h>
#include <stdlib.h>

void fibonacciSir(int n);

int main()
{
    int n;
    printf("Introdu numarul pana la care doresti sa afisezi sirul lui Fibonacii: ");
    scanf("%d", &n);

    fibonacciSir(n);

    return 0;
}

void fibonacciSir(int n)
{
    long long int f1 = 0, f2 = 1, nextTerm;

    printf("\nSirul lui Fibonacci este: %d %d ", f1, f2);
    nextTerm = f1 + f2;

    while (nextTerm < n)
    {
        printf("%d ", nextTerm);
        f1 = f2;
        f2 = nextTerm;
        nextTerm = f1 + f2;
    }
    printf("\n");
}
