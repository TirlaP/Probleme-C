#include <stdio.h>
#include <stdlib.h>

/*
    Să se scrie un program care citeşte un şir de caractere format
    din cuvinte separate prin unul sau mai multe spații şi elimină
    din șir toate spațiile inutile.
*/

int main()
{
    char s[1000],sep[]=" ", *p, c[50];
    gets(s);
    p=strtok(s, sep);
    while(p!=NULL)
    {
        strcpy(c,p);
        printf("%s ", c);
        p=strtok(NULL,sep);
    }
    return 0;
}
