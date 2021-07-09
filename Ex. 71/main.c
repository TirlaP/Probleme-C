#include <stdio.h>
#include <stdlib.h>

/**
    Scrie un program care sa creeze o lista simplu inlantuita si
    sa realizeze interschimbarea a doua elemente a unei liste
    simplu inlantuite prin modificarea legaturilor
*/

typedef struct Nod
{
    int valoare;
    struct Nod* next;
}Nod;

int main()
{
    Nod* cap = NULL;
    int n;
    printf("Introdu numarul de noduri: ");
    scanf("%d", &n);
    creareLista(&cap, n);
    interschimbareElemLista(&cap);
    afisare(cap);
    return 0;
}

void creareLista(Nod** cap, int n)
{
    int valoare;

    Nod* temp = NULL;
    Nod* p = NULL;

    for(int i = 0; i < n; i++)
    {
        temp = malloc(sizeof(Nod));
        printf("\nIntrodu valoarea de pe nodul %d: ", i + 1);
        scanf("%d", &(temp->valoare));
        temp->next = NULL;

        if (*cap == NULL)
        {
            *cap = temp;
        }
        else
        {
            p = *cap;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
}

void interschimbareElemLista(Nod** cap)
{
    int elem1, elem2;
    printf("\nIntrodu elementele pe care vrei sa le interschimbi: ");
    scanf("%d%d", &elem1, &elem2);

    Nod* curr = *cap;
    while(curr->next != NULL)
    {
        if (curr->next->valoare == elem1)
        {
            Nod* urm = *cap;
            while(urm->next != NULL)
            {
                if (urm->next->valoare == elem2)
                {
                    Nod* temp = urm->next;
                    urm->next = curr;
                    curr = temp->next;
                    return;
                }
                urm = urm->next;
            }
        }
        curr = curr->next;
    }
}

void afisare(Nod* cap)
{
    Nod* curr = cap;
    while (curr != NULL)
    {
        printf("%d ", curr->valoare);
        curr = curr->next;
    }
}


