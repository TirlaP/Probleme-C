#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <conio.h>

/// Functia myprintf
void myprintf(char *msg, ...);

int main()
{
    int n;
    scanf("%d", &n);
    int *sir;
    sir = malloc(n * sizeof(n));

    for (int i = 0; i < n; i++)
        sir[i] = rand() % 100;

    system("cls");

    for (int i = 0; i < n; i++)
    myprintf("\n[START] main( ) \n");
    myprintf("\nSuma int = %d ", 3 + 2);
    myprintf("\nSuma int = %d, Suma float = %f ", 3 + 2, 3.1f + 3.15f);


    myprintf("\nSuma int = %d, Suma float = %f %t\n", 3 + 2, 3 + 3.15f);
    myprintf("\n[END] int main( void ) \n");

    return 0;
}

void myprintf(char *msg, ...)
{
    char buf[20];
    int i;
    va_list va;
    va_start(va, msg);

    for (i = 0; i < strlen( msg ); i++)
    {
        if (msg[i] != '%')
            putchar(msg[i]);
        else
            switch( msg[++i] )
        {
        case'd':
            fputs(itoa( va_arg( va, int), buf, 10), stdout);
            break;
        case'f':
            fputs(gcvt( va_arg( va, double), 10, buf), stdout);
            break;
        default:
            putch('\01');
        }
    }


    va_end(va);
}
