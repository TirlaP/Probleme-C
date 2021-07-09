#include <stdio.h>
#include <stdlib.h>

/**
    Write a program to add, subtract and multiply two complex
    numbers using structures to function.
*/

struct complex {
    int real;
    int imag;
};

struct complex add(struct complex a, struct complex b)
{
    struct complex d;
    d.real = a.real + b.real;
    d.imag = a.imag + b.imag;
}

struct complex sub(struct complex a, struct complex b)
{
    struct complex d;
    d.real = a.real - b.real;
    d.imag = a.imag - b.imag;
}

struct complex multiply(struct complex a, struct complex b)
{
    struct complex d;
    d.real = (a.real * b.real) - (a.imag * b.imag);
    d.imag = (a.real * b.real) + (a.imag * b.imag);
}

int main()
{
    struct complex number1, number2;

    printf("\nIntrodu primul numar:\n");
    printf("\nIntrodu partea reala: ");
    scanf("%d", &number1.real);
    printf("\nIntrodu partea imaginara: ");
    scanf("%d", &number1.imag);

    printf("\nIntrodu al doilea numar:\n");
    printf("\nIntrodu partea reala: ");
    scanf("%d", &number2.real);
    printf("\nIntrodu partea imaginara: ");
    scanf("%d", &number2.imag);

    struct complex addition = add(number1, number2);
    struct complex substract = sub(number1, number2);
    struct complex multip = multiply(number1, number2);

    printf ("Addition: %d + %di\n", addition.real, addition.imag);
    printf ("Substraction: %d - %di\n", substract.real, substract.imag);
    printf ("Multiply: %d * %di\n", multip.real, multip.imag);


    return 0;
}
