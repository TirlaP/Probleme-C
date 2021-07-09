#include <stdio.h>
#include <string.h>

#define SIZE 256
/**
    Impartiti un sir citit de la tastatura in mai multe cuvinte
    delimitate de caracterele ",.;:' ":
*/

int main()
{
    char str[SIZE];
    gets(str);

    char *p;
    p = strtok(str, ",.;:' ");

    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, ",.;:' ");
    }



    return 0;
}
