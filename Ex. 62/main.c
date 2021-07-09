#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
    Să se realizeze o aplicaţie pentru lucrul cu numere raţionale
    (valori numerice ce pot fi scrise sub formă de fracţie) şi
    anume: citirea, afişarea, sumarea şi produsul a două numere
    astfel de numere
*/

typedef struct
{
    int numarator;
    int numitor;

} rational;

int main()
{
    rational n1, n2;
    citire(&n1, "Nr1");
    ireductibil(n1);
    citire(&n2, "Nr2");
    ireductibil(n2);

    afisare(n1, "Nr1");
    afisare(n2, "Nr2");

    rational s;
    s = adunare(n1, n2);
    afisare(s, "Nr1 + Nr2");

    rational p;
    p = inmultire(n1, n2);
    afisare(s, "Nr1 * Nr2");

    return 0;
}

void citire(rational *x, char c)
{
    printf("Introdu numarul rational %c:\n", c);
    printf("\tnumaratorul: \n");
    scanf("%d", &x->numarator);
    int n;
    do
    {
        printf("\tnumaratorul: \n");
        scanf("%d", &n);
    }
    while (n == 0);

    x->numitor = n;
    ireductibil(x);

}

void afisare(rational x, char c[])
{
    printf("Numarul rational %s: %d/%d\n", c, x.a, x.b);
}

rational adunare(rational x, rational y)
{
    rational r;
    r.numarator = x.numarator * y.numitor + y.numarator * x.numitor;
    r.numitor = x.numitor * y.numitor;
    ireductibil(r);

    return r;
}

rational inmultire()
{
    rational r;
    r.numarator = x.numarator * y.numarator;
    r.numitor = x.numitor * y.numitor;
    ireductibil(r);
}

int cmmdc(int a, int b)
{
    if (a == b)
        return a;
    else if (a > b)
        return cmmdc(a - b, b);
    else
        return cmmdc(a, b - a);
}

void ireductibil( rational x)
    {
        if (x.numitor < 0)
        {
            x.numarator = -x.numarator;
            x.numitor = -x.numitor;
        }
        if (x.numarator == 0)
        {
            x.numitor = 1;
        }
        else if (abs(x.numarator) != 1 && abs(x.numitor) != 1)
        {
            int d = cmmdc(abs(x.numarator), abs(x.numitor));
            x.numarator = x.numarator / d;
            x.numitor = x.numitor / d;
        }
    }
