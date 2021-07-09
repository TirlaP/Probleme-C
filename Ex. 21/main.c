#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Un număr lung (cu o valoare mult mai mare decât maximul reprezentabil
    pe un tip de date întreg standard din C), poate fi reprezentat ca un
    vector char *v de cifre (considerate valori de tip char), în felul
    următor: ...
*/

char *build_number(long long nr);
char *add_numbers(char *a, char *b);

int main()
{
    long long nr1, nr2;
    scanf("%ld%ld", &nr1, &nr2);
    char *number1 = build_number(nr1);
    char *number2 = build_number(nr2);

    char *c = add_numbers(number1, number2);

    puts(c);

    return 0;
}

/**
    a) Scrieţi o funcţie care construieşte vectorul de cifre asociat
    unui număr întreg simplu (de tipul int):
*/
char *build_number(long long nr)
{

    long long i = 0, aux = nr;

    while (aux != 0)
    {
        i++;
        aux /= 10;
    }

    char *number = malloc(i * sizeof(char));
    sprintf(number, "%d", nr);

    return number;
}

/**
     b) Scrieţi o funcţie care adună două numere lungi şi întoarce
     ca rezultat un alt număr lung:
*/
char *add_numbers(char *a, char *b)
{
    int x = atoi(a) + atoi(b);
    char *number = malloc(1 * sizeof(a));

    sprintf(number, "%d", x);

    return number;
}

/**
    c) Scrieţi un program care calculează şirul Fibonacci folosind
    numere lungi. Se cer primii 100 de termeni ai şirului, afişaţi
    pe câte o linie în parte.
*/


