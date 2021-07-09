char **citireNume(int n)
{
    char **sir = 0;
    int i;

    sir = (char **) malloc(n * sizeof(char));
    if (sir == 0)
    {
        printf("Eroare la alocare.");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        sir[i] = (char *) malloc(256 * sizeof(char));
        if (sir[i] == 0)
        {
            printf("Eroare la alocare.");
            exit(EXIT_FAILURE);
        }
    }

    printf("\nIntroduceti numele elevilor:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. ", i + 1);
        scanf("%s", sir[i]);
    }

    return sir;
}

char **citirePrenume(int n)
{
    char **sir = 0;
    int i;

    sir = (char **) malloc(n * sizeof(char));
    if (sir == 0)
    {
        printf("Eroare la alocare.");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        sir[i] = (char *) malloc(256 * sizeof(char));
        if (sir[i] == 0)
        {
            printf("Eroare la alocare.");
            exit(EXIT_FAILURE);
        }
    }

    printf("\nIntroduceti prenumele elevilor:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. ", i + 1);
        scanf("%s", sir[i]);
    }

    return sir;
}

int *citireVarsta(int n)
{
    int *sir = 0;
    int i;

    sir = (int *) malloc(n * sizeof(int));
    if (sir == 0)
    {
        printf("Eroare la alocare.");
        exit(EXIT_FAILURE);
    }

    printf("\nIntroduceti varsta elevilor:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. ", i + 1);
        scanf("%d", &sir[i]);
    }

    return sir;
}

void sortareElevi(char **nume, char **prenume, int *varsta, int n, int choice)
{
    int sortat;

    if (choice == 1)
    {
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (strcmp(nume[i], nume[i + 1]) > 0)
                {
                    swapStrings(nume[i], nume[i + 1]);
                    swapStrings(prenume[i], prenume[i + 1]);
                    swapIntegers(&varsta[i], &varsta[i + 1]);
                    sortat = 0;
                }
            }

        }while (sortat == 0);
    }
    else if (choice == 2)
    {
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (strcmp(prenume[i], prenume[i + 1]) > 0)
                {
                    swapStrings(nume[i], nume[i + 1]);
                    swapStrings(prenume[i], prenume[i + 1]);
                    swapIntegers(&varsta[i], &varsta[i + 1]);
                    sortat = 0;
                }
            }

        }while (sortat == 0);
    }
    else if (choice == 3)
    {
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (varsta[i] > varsta[i + 1])
                {
                    swapStrings(nume[i], nume[i + 1]);
                    swapStrings(prenume[i], prenume[i + 1]);
                    swapIntegers(&varsta[i], &varsta[i + 1]);
                    sortat = 0;
                }
            }

        }while (sortat == 0);
    }
    else
    {
        printf("\nOptiune invalida!\n");
    }
}

void afisare(char **nume, char **prenume, int *varsta, int n)
{
    int i;
    printf("\n\nElevii din baza de date sunt:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. %s %s cu varsta de %d ani.\n", i + 1, nume[i], prenume[i], varsta[i]);
    }
}

void swapStrings(char** a, char** b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void swapIntegers(int *a, int *b)
{
    int *aux = *a;
    *a = *b;
    *b = aux;
}


