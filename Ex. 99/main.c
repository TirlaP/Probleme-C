#include <stdio.h>
#include <stdlib.h>

/*
    Se dă un şir de caractere ce conţine cuvinte formate din
    litere mici ale alfabetului englez, separate prin unul sau mai
    multe spații. Înaintea primului cuvânt nu există spații, și
    nici după ultimul. Să se modifice șirul dat, astfel încât să
    se înlocuiască fiecare cuvânt cu exact trei litere din șir cu
    simbolul *.
*/

int main ()
{
    char sir[256];
    gets(sir);

    char *cuv = strtok(sir, " ");

    while (cuv != NULL)
    {
        if (strlen(cuv) == 3)
            printf("*");
            else
                printf("%s", cuv);
            printf(" ");
        cuv = strtok(NULL, " ");
    }
    return 0;
}
