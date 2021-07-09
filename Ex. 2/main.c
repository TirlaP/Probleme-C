#include <stdio.h>
#include <stdarg.h>

/// Functia de sortare

void Sort(char msg[], ...);

int main()
{
    Sort("Numerele sortate sunt :", 3, 2, 9, 3, 1, 0);
    Sort("Numerele sortate sunt :", 11, 2, -3, 4, 21, 44, 12, 0);

    return 0;
}

void Sort( char msg[], ...)
{
    va_list ap;
    int arg, v[100], i, temp, n = 0;
    va_start( ap, msg);
    printf("\n\n [MESAJ] - %s", msg);

    while((arg = va_arg(ap, int)) != 0)
    {
        v[n++] = arg;
    }
    va_end(ap);

    int sortat;
    do
    {
        sortat = 1;
        for(i = 0; i < n -1; i++)
        {
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                sortat = 0;
            }
        }
    }while (sortat == 0);

    for (i = 0; i < n; i++)
        printf("\n v[%d] = %d", i, v[i]);
    printf("\n");

}
