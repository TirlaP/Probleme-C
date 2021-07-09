#include <stdio.h>
#include <stdlib.h>

/*
    Într-un grup sunt n prieteni. Când se întâlnesc se salută,
    fiecare dând mână cu toți ceilalți. Câte strângeri de mână au
    loc?
*/

int main()
{
    long long int n,nr;

    printf("Introdu numarul n: ");
    scanf("%d", &n);

    nr = n*(n-1)/2;
    printf("%d", nr);
    return 0;
}
