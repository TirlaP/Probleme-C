#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct concert {
    char trupa[100];
    char locatia[100];
    int luna, ziua;
};

int main()
{
    struct concert *c;

    c = (struct concert *) malloc(sizeof(struct concert));
    if (!c)
    {
        printf("Eroare alocare memorie.\n");
        exit(-1);
    }

    ///În cazul când folosim pointeri la structuri, pentru a
    /// accesa câmpurile structurii se folosește operatorul ->.
    strcpy(c->trupa, "Phoenix");
    strcpy(c->locatia, "Filarmonica de Stat Banatul");
    c->luna = 3;
    c->ziua = 2;

    printf("%02d.%02d: %s - %s\n", c->luna, c->ziua, c->trupa, c->locatia);

    free(c);

    return 0;
}
