#include <stdio.h>
#include <stdlib.h>
/*
    Gigel are o bucată de hârtie cu dimensiunile N*M și vrea să o
    taie în bucăți cu dimensiunile 1*1, respectând regulile:

    - poate să taie o singură foaie la un moment dat. Nu poate
    suprapune mai multe foi și să le taie în același timp;
    - fiecare tăietură se face dintr-o parte în alta a foii, pe
    verticală sau orizontală.

    Scrieți un program care să citească numerele N și M și să determine numărul de tăieturi care trebuie efectuate.
*/

int main ()
{
    long long int N,M,S;
    printf("Introdu numarul de N: ");
    scanf("%d", &N);
    printf("Introdu numarul de M: ");
    scanf("%d", &M);
    if(M==1 && N==1)
    {
        S=0;
    }else{
        if(N==2 && M==1)
        {
            S = 1;
        }else{
            if(N==1 && M==2)
            {
                S=1;
            }
            S = M*N-1;
        }
        }
    printf("%d", S);
    return 0;
}
