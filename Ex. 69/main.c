#include <stdio.h>
#include <stdlib.h>

/**
    Scrie un program care sa creeze o lista simplu inlantuita.
    Dupa creare, se va introduce un nou nod in interiorul listei
    si se va afisa lista.
*/

typedef struct Nod
{
    int valoare;
    struct Nod * next;
}Nod;

Nod * creareLista(int n);
void inserareInterior (Nod* cap, int val);
void afisareLista(Nod * cap);

int main()
{
    int n, val;
    Nod * cap = NULL;

    printf("Introdu numarul de noduri: ");
    scanf("%d", &n);

    cap = creareLista(n);
    printf("Introdu valoarea pe care doresti sa o inserezi in interiorul listei: ");
    scanf("%d", &val);

    inserareInterior(cap, val);

    afisareLista(cap);

    return 0;
}

Nod * creareLista(int n)
{
    Nod * cap = NULL;
    Nod * temp = NULL;
    Nod * p = NULL;

    for (int i = 0; i < n; i++)
    {
        temp = (Nod*)malloc(sizeof(Nod));
        printf("\nIntrodu nodul de pe pozitia %d: ", i + 1);
        scanf("%d", &(temp->valoare));
        temp->next = NULL;

        if (cap == NULL)
        {
            cap = temp;
        }
        else
        {
            p = cap;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return cap;
}

void inserareInterior (Nod* cap, int val)
{
    Nod *elem = (Nod*)malloc(sizeof(Nod));
    elem->valoare = val;
    elem->next = NULL;

    Nod* p = NULL;

    /// lista vida
    if (cap == NULL)
    {
        cap = elem;
        return;
    }

    /// inserare la inceputul listei
    if (cap == p)
    {
        elem->next = cap;
        cap = elem;
        return;
    }

    /// inserare in interior
    elem->next = p->next;
    p->next = elem;
}

void afisareLista(Nod * cap)
{
    Nod * p = cap;

    while (p != NULL)
    {
        printf("\t%d->", p->valoare);
        p = p->next;
    }
}
