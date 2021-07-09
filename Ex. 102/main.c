#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functii.h"
/// Factorial recursiv

int main(int argc, char *argv[])
{
   int i;
   char sir[256];

   FILE *in = fopen(argv[1], "rt");





   do
   {
       system("cls");
       printMenu1();

       switch(getch())
       {
       case '1':
            printf("Introdu sirul de caractere: \n");
            fgets(sir, 256, in);
            afisareSir(sir, argv);
            printf("Press any key to continue !");
            getch();
            break;
       case '2':
            printf("Press any key to continue !");
            getch();
            break;
       case '3':
            printf("Press any key to continue !");
            getch();
            break;
       case '4':
            printf("Press any key to continue !");
            getch();
            break;
       case '5':
            printf("Press any key to continue !");
            getch();
            break;
       case '6':
            printf("Press any key to continue !");
            getch();
            break;
       case '7':
            printf("Press any key to continue !");
            getch();
            break;
       case '8':
            printf("Press any key to continue !");
            getch();
            break;
       case '9':
            printf("Press any key to continue !");
            getch();
            break;
       }
   }while(1);

    return 0;
}

