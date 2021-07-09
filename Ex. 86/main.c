#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, mat[10][10];

    do
    {
        system("cls");
        printMenu();

        switch(getch())
        {
        case '1':
            printf("\nIntrodu numarul de linii: ");
            scanf("%d", &n);
            printf("Introdu numarul de coloane: ");
            scanf("%d", &m);
            printf("Introdu numerele din matrice: \n");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    scanf("%d", &mat[i][j]);
                }
            }
            printf("\n\nPress any key to continue!");
            getch();
            break;
        case '2':
            printf("\nNumerele din matrice sunt: \n");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    printf("%d ", mat[i][j]);
                }
                printf("\n");
            }
            printf("\n\nPress any key to continue!");
            getch();
            break;
        case '3':
            sumaDiag(n, m, mat);
            printf("\n\nPress any key to continue!");
            getch();
            break;
        case '4':
            printf("\n\nAti ales sa iesiti din program!");
            exit(1);
            break;
        default:
            printf("Optiunea aleasa nu este valabila momentan!");
            break;
        }
    }
    while(1);

    return 0;
}

void printMenu()
{
    printf("-----------< MENIU >-----------");
    printf("\n1. Citire matrice");
    printf("\n2. Afisare matrice");
    printf("\n3. Suma elemente diagonala principala");
    printf("\n4. Iesire program");
    printf("\nIntrodu optiunea dorita: ");

}

void sumaDiag(int n, int m, int mat[10][10])
{
    int suma = 0;
    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                    suma += mat[i][j];
            }
        }
        printf("\nSuma elementelor de pe diagonala principala este %d.\n", suma);
    }
    else
        printf("\nMatricea data nu este patratica!\n");

}
