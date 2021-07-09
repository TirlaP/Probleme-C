#include <stdio.h>
#include <stdlib.h>
/*
    Să se scrie un program care citește un șir de caractere în
    care cuvintele sunt formate numai din litere mici ale
    alfabetului englez și sunt separate prin câte un spațiu și
    elimină litera din mijloc a fiecărui cuvânt cu număr impar de
    litere (cel puțin trei).
*/

int main ()
{
    int n, gasit = 0;
    char sir[101], sir2[101] = {0};
    gets(sir);

    char *cuv = strtok(sir, " ");
    while (cuv != NULL)
    {
        n = strlen(cuv);
        if (n % 2 == 1 && n > 2)
        {
            gasit = 1;
            strcpy (cuv + n/2, cuv + n/2 + 1);
        }
        strcat(sir2, cuv);
        strcat(sir2, " ");
        cuv = strtok(NULL, " ");
    }

    strcpy(sir, sir2);
    if (gasit != 0)
        printf("%s", sir);
    else
        printf("nu exista");
    return 0;
}
