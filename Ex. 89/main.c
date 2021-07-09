#include <stdio.h>
#include <stdlib.h>

/*
    Într-un stup, pe un fagure de miere infinit, trăiește o albină
    foarte harnică. Fagurele este alcătuit din celule hexagonale,
    fiecare celulă având șase vecini. În prima zi albina depune
    nectar într-o singură celulă. În fiecare din zilele
    următoarele, albina depune nectar în celulele vecine cu cele
    în care a fost deja depus nectar. Aflați în câte celule este
    depus nectar după n zile.
*/

int main ()
{
    int n;
    long long rez;

    printf("Introdu numarul n: ");
    scanf("%d", &n);

    if (n == 1)
        rez = 1;
    else {
        rez = 1;
        for (int i = 1; i < n; i++)
            rez += i * 6;
    }
    printf("%d", rez);
    return 0;

}
