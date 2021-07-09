void citire(int *n, int sir[])
{
    printf("Introdu numarul de elemente: ");
    scanf("%d", n);

    printf("Introdu numerele din sir: \n");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", &sir[i]);
    }
}

void afisare(int n, int sir[])
{
    printf("Elementele sirului sunt: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sir[i]);
    }
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
