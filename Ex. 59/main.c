#include <stdio.h>
#include <stdlib.h>

/**
    Declararea unei înregistrări şi folosirea acesteia.
*/

typedef struct {
    int cod_angajat;
    char nume[30];
    char prenume[30];
    struct {
        int an, luna, zi;
    } data_angajarii;

    float salariu;

} angajat;

int main()
{
    angajat x;

    printf("Introdu datele angajatului:\n");
    printf("Cod: ");
    scanf("%d", &x.cod_angajat);
    printf("Nume: ");
    scanf("%s", &x.nume);
    printf("Prenume: ");
    scanf("%s", &x.prenume);
    printf("\nIntrodu data angajarii:\n");
    printf("An: ");
    scanf("%d", &x.data_angajarii.an);
    printf("Luna: ");
    scanf("%d", &x.data_angajarii.luna);
    printf("Ziua: ");
    scanf("%d", &x.data_angajarii.zi);
    printf("\nSalariu: ");
    scanf("%f", &x.salariu);

    printf("Datele angajatului sunt:\n");
    printf("Nume: %s %s \n", x.nume, x.prenume);
    printf("Data angajarii: %d.%d.%d\n",
            x.data_angajarii.zi, x.data_angajarii.luna, x.data_angajarii.an);
    printf("\nSalariu: %.2f $\n", x.salariu);

    return 0;
}
