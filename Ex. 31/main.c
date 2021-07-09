#include <stdio.h>
#include <string.h>

#define N 256

/**
    Afisati lungimea unui sir citit de la tastatura.
*/

int main ()
{
    char text[N];
    printf("Introduceti un text: ");

    gets(text);
    printf("Textul are %u caractere.\n", strlen(text));

    return 0;
}
