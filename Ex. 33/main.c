#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SEPARATORS " ,."

/**
    In momentul actual programul numara cate cuvinte doar cu litere
    mici se gasesc intr-un sir de caractere.

    Sa se numere cate cuvinte au cel putin un caracter din sirul
    "api".
*/

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


int main()
{
    char sentence[256];
    printf("Introdu sirul dorit: ");
    gets(sentence);

    count_lowercases_words(sentence);

    return 0;
}
