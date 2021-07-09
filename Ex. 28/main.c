#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Funcția IndexOf primește ca parametri un șir de caractere s și un
    caracter ch și returnează cea mai din stânga poziție unde se
    găsește ch în șir, sau returnează -1 dacă ch nu apare în șir.

    Funcția LastIndexOf primește ca parametri un șir de caractere s
    și un caracter ch și returnează cea mai din dreapta poziție unde
    se găsește ch în șir, sau returnează -1 dacă ch nu apare în șir.

    Funcția NthIndex primește ca parametri un șir de caractere s, un
    caracter ch și un număr întreg k. Presupunând că ch apare de n
    ori în șir, atunci, dacă 1 ≤ k ≤ n, funcția returnează poziția
    unde caracterul ch apare a k-a oară. În caz contrar, funcția
    returnează -1.
*/

int IndexOf(char s[], char ch);
int LastIndexOf(char s[], char ch);
int NthIndex(char s[], char ch, int k);

int main()
{
    char sir[256], ch;
    gets(sir);
    scanf("%c", &ch);

    int cautat;
    scanf("%d", &cautat);

    printf("IndexOf: %d\nLastIndexOf: %d\nNthIndex: %d\n", IndexOf(sir, ch), LastIndexOf(sir, ch), NthIndex(sir, ch, cautat));

    return 0;
}

int IndexOf(char s[], char ch)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] == ch)
            return i;
        i++;
    }
    return -1;
}

int LastIndexOf(char s[], char ch)
{
    int i = strlen(s) - 1;

    while (s[i])
    {
        if (s[i] == ch)
            return i;
        i--;
    }
    return -1;
}

int NthIndex(char s[], char ch, int k)
{
    int i = 0, cnt = 0;

    while (s[i])
    {
        if (s[i] == ch)
        {
            cnt++;
        }
        if (cnt == k)
            return i;
        i++;

    }
    return -1;
}



