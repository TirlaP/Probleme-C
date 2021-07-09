#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Problema 1

    Folosind struct și union, definiți o structură de
    date care să poată memora următoarele informații despre
    viețuitoare:
    -tipul (poate fi: mamifer, insectă, pește, pasăre);
    -durata medie de viață în ani;

    -dacă e mamifer:
    -perioada de gestație;
    -numărul mediu de pui pe care îi naște;

    -dacă e insectă:
    -numărul de picioare;
    -dacă poate să zboare sau nu;
    -dacă este periculoasă sau nu pentru om;

    -dacă e pește:
    -tipul de apă: sărată/dulce;
    -adâncimea maximă la care se poate întâlni;
    -viteza maximă de înot;

    -dacă e pasăre:
    -anvergura aripilor;
    -altitudinea maximă de zbor;
    -viteza maximă de zbor;

    Definiți structura în așa fel încât memoria consumată să fie
    minimă. Citiți și afișați informațiile despre o viețuitoare.

*/

typedef struct {
    char tip[10];
    int durataViata;
    union {
        struct {
            int perioadaGestatie, nrPui;
        }mamifer;

        struct {
            int nrPicioare;
            char zbor[3], periculos[3];
        }insecta;

        struct {
            char tipApa[10];
            int adancimeaMax, vitezaInot;
        }peste;

        struct {
            int anverguraAripi, altitidineMax, vitezaZbor;
        }pasare;
    };

} vietuitoare;

vietuitoare citire()
{
    vietuitoare v;
    printf("\nIntroduceti tipul de vietuitoare: (mamifer/ insecta/ peste/ pasare): ");
    scanf("%s", &v.tip);
    printf("\nIntroduceti durata de viata: ");
    scanf("%d", &v.durataViata);
    if (strcmp(v.tip, "mamifer") == 0)
    {

    }


    return v;
}

void afisareVietuitoare(vietuitoare v)
{

}

int main()
{
    vietuitoare V = citire();
    afisareVietuitoare(V);

    return 0;
}
