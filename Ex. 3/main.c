#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
/// Functia ce calculeaza SUMA a N elemente intregi

int Suma (int n, ...);

int main()
{
    int s;

    system("cls");
    s = Suma(4, -2, 13, 45, 30);
    printf("\nSuma elementelor este: %d\n", s);

    return 0;
}

int Suma(int n, ...)
{
    va_list list_p;
    int suma = 0, i;

    va_start(list_p, n);

    for(i = 0; i < n; i++)
        suma += va_arg(list_p, int);

    va_end(list_p);

    return suma;

}
