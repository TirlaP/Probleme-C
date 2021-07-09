#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    Parametrul cale memorează un șir de caractere format din litere
    mici și semnul \ și reprezintă o succesiune de foldere incluse
    unul în altul. Funcția trebuie să memoreze fiecare folder pe câte
    o linie a matricei d și să returneze numărul de foldere conținute
    în cale.
*/

int Path(const char cale[], char d[101][101]);
int litera(char ch);

int main()
{
    const char cale[101];
    char d[101][101];

    gets(cale);

    int n = Path(cale, d);
    printf("%d\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", d[i]);
    }
    return 0;
}

int litera(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;

    return 0;
}

int Path(const char cale[], char d[101][101]){
    int i = 0, c = 0, j = 0;
    while(cale[i]){
        if(!litera(cale[i]))
            c++, j = 0;
        else{
            d[c][j] = cale[i];
            j++;
        }
        i++;
    }
    return c + 1;
}



