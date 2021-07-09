void citireNumar(int *n)
{
    printf("\n * Ati ales sa continuati programul.\n");
    printf("\n * Calculatorul tocmai ce a ales un numar.\n");
    int toBeGuessed = rand() % 10;
    printf("\n * Ghiceste numarul ales de calculator: ");
    scanf("%d", n);
    printf("\n -> Alegerea ta este %d.\n", *n);

    if (*n == toBeGuessed)
        printf("\n - Ai ales corect.\n");
    else
        printf("\n - Din pacate, nu ai facut alegerea corecta.\n\n- Numarul era %d.", toBeGuessed);
}

