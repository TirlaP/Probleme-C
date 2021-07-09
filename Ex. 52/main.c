#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Scrieti un program care citeste dintr-un fisier text pana la
    apatiria caracterului '.', iar apoi afiseaza sirul citit pe
    ecran.
*/

int main()
{
    FILE *fp = fopen("date.txt", "r");

    char sir[256][10], read[10];

    if (fp == NULL)
    {
        perror("Error opening file");
        return(-1);
    }

    int i = 0, cnt = 0;
    do
    {
        fscanf(fp, "%s", read);
        strcpy(sir[i++], read);

        if (feof(fp) || strchr(read, '.'))
        {
            break;
        }

    }while(1);

    int n = i;

    for (i = 0; i < n; i++)
    {
        printf("%s\n", sir[i]);
    }

    fclose(fp);

    return 0;
}

