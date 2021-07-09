void citireNumar(int *nr)
{
    printf("\n * Introdu caruia doresti sa ii faci suma cifrelor: ");
    scanf("%d", nr);
}

void sumCif(int *nr)
{
    int sum = 0, aux = *nr;
    while (aux != 0)
    {
        sum += aux % 10;
        aux /= 10;
    }

    printf("\n * Suma cifrelor numarului %d este: %d.\n", *nr, sum);
}
