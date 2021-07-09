#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Prescurtat(char sir[])
{
    char *cuv = strtok(sir, " .");
    char aux[101], pres[20][20] = {"COLEGIUL", "LICEUL", "NATIONAL", "TEORETIC"};

    aux[0] = '\0';

    while (cuv != NULL)
    {
        int n = strlen(cuv);

        for (int i = 0; i < 4; i++)
            if (strstr(pres[i], cuv))
            {
                cuv[n] = '\0';
                strcat(aux, pres[i]);
            }
            else
                strcat(aux, cuv);

        cuv = strtok(NULL, " .");
        if (cuv)
            strcat(aux, ' ');
    }
    printf("%s\n", aux);
}

int main()
{
    char sir[256];
    gets(sir);

    Prescurtat(sir);
    return 0;
}
