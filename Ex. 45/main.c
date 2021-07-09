#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct punct
{
    float x, y;
};

struct dreptunghi
{
    struct punct p1, p2;
};

int main()
{
    struct dreptunghi d;

    printf("Introdu coordonatele primului colt: ");
    scanf("%f%f", &d.p1.x, &d.p1.y);
    printf("Introdu coordonatele celui de-al doilea colt: ");
    scanf("%f%f", &d.p2.x, &d.p2.y);

    printf("(%.2f, %.2f) - (%.2f, %.2f)\n", d.p1.x, d.p1.y,
           d.p2.x, d.p2.y);

    return 0;
}
