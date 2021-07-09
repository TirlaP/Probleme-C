#include <stdio.h>
#include <stdlib.h>

/**
    Scrie un program care sa creeze si sa afiseze o lista simplu
    inlantuita.
*/

typedef struct Nod
{
    int valoare;
    struct Nod* next;
} Nod;

Nod * creareLista(int n);

void afisareLista(Nod * cap);

int main()
{
    int n;
    Nod * cap = NULL;

    printf("\nIntrodu numarul de noduri din lista: ");
    scanf("%d", &n);

    cap = creareLista(n);
    afisareLista(cap);

    return 0;
}

Nod * creareLista(int n)
{
    int i = 0;
    Nod * cap = NULL;
    Nod * temp = NULL;
    Nod * p = NULL;

    for (i = 0; i < n; i++)
    {
        /// cream cate un nod individual

        temp = (Nod*)malloc(sizeof(Nod));
        printf("\nIntrodu valoarea pentru nodul %d: ", i + 1);
        scanf("%d", &(temp->valoare));
        temp->next = NULL;

        /// daca lista e goala, facem temp primul nod
        /// (adresa de inceput)
        if (cap == NULL)
        {
            cap = temp;
        }
        else
        {
            p = cap;
            /// parcurgem lista pana ajungem la final
            while(p->next != NULL)
            {
                p = p->next;
            }
            /// la sfarsitul listei adaugam nodul nou creat
            p->next = temp;
        }
    }
    /// returnam adresa de inceput
    free(temp);
    return cap;
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

