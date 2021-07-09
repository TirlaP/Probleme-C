#include <stdio.h>
#include <stdlib.h>

/*
    Scrieți un program care citește un cuvânt cu cel mult 15
    litere mici ale alfabetului englez și apoi un text cu cel
    mult 255 de caractere (cuvinte formate din litere mici ale
    alfabetului englez separate prin unul sau mai multe spații)
    și care afișează șirul obținut prin inserarea în text a
    caracterului ? după fiecare apariție a cuvântului citit. Dacă
    în text nu apare cuvântul citit, se va afișa mesajul NU APARE.
*/

int main(int argc, char *argv[])
{
    char cuv[16], aux[500], sir[500], *t;
    int este = 0;
    FILE *in = fopen(argv[1], "rt");

    if (in == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }

    fscanf(in, "%s", cuv);
    fgets(sir, 500, in);
    fclose(in);

    FILE *out = fopen(argv[2], "wt");
    if (out == NULL)
    {
        fprintf(stderr, "ERROR: Can't open this file!");
        exit(EXIT_FAILURE);
    }

    aux[0] = 0;

    t=strtok(sir, " ");

    while(t)
    {
        strcat(aux, t);
        if(strcmp(t, cuv)==0)
        {
            strcat(aux, "?");
            este = 1;
        }
        strcat(aux, " ");

        t=strtok(NULL, " ");
    }
    if(!este)
        fprintf(out,"NU APARE");
    else
    {
        strcpy(sir, aux);
        sir[strlen(sir)-1] = 0;
        fprintf(out, "%s ", sir);
    }

    fclose(out);
}
