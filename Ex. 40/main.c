#include <stdio.h>
#include <stdlib.h>
#include "functii.h"
#include <string.h>

/**
    Se dă N de la tastatură. Citiţi pentru fiecare N numele,
    prenumele şi vârsta elevului respectiv, alocând întreaga
    memorie în mod dinamic pentru fiecare elev nou (lungimea
    numelui şi a prenumelui se consideră a fi 20 de caractere,
    iar vârsta se consideră între 0 şi 100). Afişaţi pe ecran, în
    funcţie de opţiunea selectata, lista citită de la tastatură,
    ordonată în funcţie de nume, prenume, respectiv vârsta.
*/

int main()
{
    char **strNume, **strPrenume;
    int n, *varsta, choice;

    printf("Introduceti numarul de elevi: ");
    scanf("%d", &n);

    strNume = citireNume(n);
    strPrenume = citirePrenume(n);
    varsta = citireVarsta(n);

    printf("\n1 -> Sortati elevii in functie de nume\n"
           "2 -> Sortati elevii in functie de prenume\n"
           "3 -> Sortati elevii in functie de varsta\n"
           "Introduceti optiunea dorita: ");
    scanf("%d", &choice);

    sortareElevi(strNume, strPrenume, varsta, n, choice);

    afisare(strNume, strPrenume, varsta, n);
    return 0;
}









