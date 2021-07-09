#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
     Să se citească o succesiune de cuvinte. Să se creeze o funcţie:
      void ordCresc(char *vectorschar[], int n); care să ordoneze
      cuvintele crescător:
      - dupa lungimea acestora
      - alfabetic
*/
char **citireSir(int n);
void afisare(char **vector, int n);
void ordCresc(char *vectorchar[], int n, int choice);
void swapStrings(char** a, char** b);

int main()
{
    char **vectorChar = 0;
    int n, i, choice;

    printf("Introdu numarul de cuvinte dorit: ");
    scanf("%d", &n);

    vectorChar = citireSir(n);

    afisare(vectorChar, n);

    printf("\n1 -> sortare crescatoare a cuvintelor dupa lungime\n"
           "2 -> sortare crescatoare a cuvintelor in ordine alfabetica\n"
           "Introdu alegerea pe care doresti sa o faci: ");
    scanf("%d", &choice);

    ordCresc(vectorChar, n, choice);

    return 0;
}

char **citireSir(int n)
{
    char **sir = 0;
    int i;
    sir = (char **) malloc(n * sizeof(char));
    if (sir == 0)
    {
        printf("Eroare la alocare!\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        sir[i] = (char *) malloc(256 * sizeof(char));
        if (sir[i] == 0)
        {
            printf("Eroare la alocare!\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("\nIntroduceti cuvintele dorite:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", *(sir + i));
    }

    return sir;
}

void afisare(char **vector, int n)
{
    int i;
    printf("\nCuvintele introduse sunt:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", vector[i]);
    }
}

void ordCresc(char **vectorChar, int n, int choice)
{
    int sortat;
    if (choice == 1)
    {
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (strlen(vectorChar[i]) > strlen(vectorChar[i + 1]))
                {
                    swapStrings(vectorChar[i], vectorChar[i + 1]);
                    sortat = 0;
                }
            }
        }
        while (sortat == 0);
    }
    else if (choice == 2)
    {
        do
        {
            sortat = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (strcmp(vectorChar[i], vectorChar[i + 1]) > 0)
                {
                    swapStrings(vectorChar[i], vectorChar[i + 1]);
                    sortat = 0;
                }
            }
        }
        while (sortat == 0);
    }
    afisare(vectorChar, n);
}

void swapStrings(char** a, char** b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}



