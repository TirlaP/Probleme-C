#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b);

int main()
{
    char str[256];
    printf("Introduceti sirul pe care doriti sa il oglinditi: ");
    gets(str);

    int n = strlen(str);

    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        swap(&str[i], &str[j]);
    }

    printf("Sirul rezultat dupa oglindire este:\n%s", str);

    return 0;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
