#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SEPARATORS " ,."
#define N 256

/**
    In momentul actual programul numara cate cuvinte doar cu litere
    mici se gasesc intr-un sir de caractere.

    Sa se realizeze o functie care intoarce un sir de caractere
    compus din cuvintele care incep cu litera mare.
*/

void count_lowercases_words(char *str);
void cuvLitMare(char *str, char *sirRez);

int main()
{
    char *sentence = malloc(N * sizeof(char));
    printf("Introdu sirul dorit: ");
    gets(sentence);

    char *sirRez = malloc(N * sizeof(char));

    cuvLitMare(sentence, sirRez);
    printf("\nSirul rezultat este: %s\n", sirRez);

    return 0;
}

void cuvLitMare(char *str, char *sirRez)
{
    char *tmp_str = strdup(str);

    int n = 0;

    if (tmp_str == NULL)
    {
        printf("Eroare la alocare\n");
        return -1;
    }

    char *word = strtok(tmp_str, SEPARATORS);
    while (word)
    {
        int lung = strlen(word);
        if (strchr("QWERTYUIOPASDFGHJKLZXCVBNM", word[0]))
            {
                for (int i = 0; i < lung; i++)
                    sirRez[n++] = word[i];
                sirRez[n++] = ' ';
            }
        sirRez[n] = '\0';
        word = strtok(NULL, SEPARATORS);
    }

    free(tmp_str);
}

void count_lowercases_words(char *str)
{
    char *tmp_str = strdup(str);
    unsigned int count = 0, rez = 0;

    if (tmp_str == NULL)
    {
        printf("Eroare la alocare\n");
        return -1;
    }

    char *word = strtok(tmp_str, SEPARATORS);
    while (word)
    {
        unsigned int i, gasit = 0;

        for (i = 0; i < strlen(word); i++)
        {
            if (isupper(word[i]))
            {
                break;
            }

            if (strchr("api", word[i]))
            {
                gasit = 1;
            }
        }

        if (gasit == 1)
            rez++;

        if (i == strlen(word))
        {
            count++;
        }

        word = strtok(NULL, SEPARATORS);
    }

    free(tmp_str);
    printf("Numarul de cuvinte al sirului este: %d\n", count);
    printf("Numarul de cuvinte care au cel putin un caracter din \"api\": %d\n", rez);
}
