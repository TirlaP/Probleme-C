#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Constante pentru cele doua moduri de utilizare a
 uniunii: ca si int sau ca si double. */
#define TIP_INT 1
#define TIP_DOUBLE 2

/**
    Se va scrie un program C ce va evidenţia diferenţele între
    folosirea unei structuri şi a unei uniuni

    a) se va folosi o structură de înregistrări
    b) se va folosi o structură tip uniune
*/

typedef struct
{
    long int a;
    char *b;
    char *c;
}exemplu1;

typedef union
{
    long int a;
    char *b;
    char *c;
}exemplu2;

void difStructura();
void difUniune();

int main()
{
    difStructura();
    difUniune();
    return 0;
}

void difStructura()
{
    exemplu1 test;
    printf("Spatiul ocupat de o variabila la structura este: %d\n", sizeof(test));
    test.a = 10;
    test.b = "ABCD";
    test.c = "EFG";
    printf("%ld\n", test.a);
    printf("%s\n", test.b);
    printf("%s\n", test.c);

}

void difUniune()
{
    exemplu2 test;
    printf("Spatiul ocupat de o variabila la uniune este: %d\n", sizeof(test));
    test.a = 10;
    test.b = "ABCD";
    test.c = "EFG";
    printf("\nIar la final valoarea ramasa in uniune va fi chiar ultima introdusa!\n");
    printf("%ld\n", test.a);
    printf("%s\n", test.b);
    printf("%s\n", test.c);

}
