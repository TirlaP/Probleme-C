#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Functie echivalenta cu functia de biblioteca strdup():
    (duplicare string)
*/

char *mystrdup(char *adr);

// Utilizare mystrdup
int main()
{
    char sir[256], *d;

    do
    {
        if (fgets(sir, 80, stdin) == NULL){
            break;
        }

        d = mystrdup(sir);
        if (d != NULL){

            fputs(d, stdout);
            free(d);
        }
        // Nu s-a reusit alocarea memoriei
        else{
            printf("Nu s-a reusit alocarea de memorie.\n");
            return 1;
        }

    }while (1);

    return 0;
}


// Alocare memorie si copiere sir
char *mystrdup(char *adr)
{
    int len = strlen(adr);
    char *rez = malloc(len + 1);

    // Daca alocarea nu a reusit, intoarcem NULL
    if (rez == NULL)
        return NULL;

   strcpy(rez, adr);

   return rez;
}
