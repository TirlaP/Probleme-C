typedef struct
{
    int val, xPos, yPos;
} triplete;

int maxx = 0;

void printMenu()
{
    printf("[-------------------------------<M E N I U>-------------------------------]\n");
    printf("\n\n\tC. Citeste matrice\n");
    printf("\tA. Afiseaza matrice\n");
    printf("\tL. Afiseaza elemente matrice diagonala principala/secundara\n");
    printf("\tV. Construire sir cu suma elementelor de pe coloane\n");
    printf("\tS. Afisare sir (V) \n");
    printf("\tN. Calculare siruri maximale - fiecare linie\n");
    printf("\tT. Identificare zone compacte colt stanga-sus de lungime 3\n");
    printf("\tI. Afiseaza informatii despre autor\n");
    printf("\tE. Terminare program\n");
    printf("\n[---------------------------------------------< alege optiunea>-----------------]");

    printf("\nIntrodu optiunea dorita: ");
}

void selectMenu()
{
    int n, m, k, mat[10][10], sir[10], fr[10] = {0};
    triplete xy[20];

    do
    {
        system("cls");
        printMenu();
        switch(getch())
        {
        case 'c':
        case 'C':
            citire(&n, &m, &k, xy, mat);
            printf("Press any key to continue!");
            getch();
            break;
        case 'a':
        case 'A':
            afisareOriginala(n, m, mat);
            printf("Press any key to continue!");
            getch();
            break;
        case 'l':
        case 'L':
            afisareDiagonale(n, m, mat);
            printf("Press any key to continue!");
            getch();
            break;
        case 'v':
        case 'V':
            construireSir(n, m, mat, sir, fr, maxx);
            printf("Press any key to continue!");
            getch();
            break;
        case 's':
        case 'S':
            afisareSir(m, sir, fr);
            printf("Press any key to continue!");
            getch();
            break;
        case 'n':
        case 'N':
            calculareMaximale(n, m, mat);
            printf("Press any key to continue!");
            getch();
            break;
        case 't':
        case 'T':
            matriciCompacte(n, m, mat);
            printf("Press any key to continue!");
            getch();
            break;
        case 'i':
        case 'I':
            infoAutor();
            printf("Press any key to continue!");
            getch();
            break;
        case 'e':
        case 'E':
            exit(EXIT_SUCCESS);
            break;
        }

    }
    while (1);
}

void citire(int *n, int *m, int *k, triplete xy[], int mat[][10])
{
    printf("Introdu numarul de linii: ");
    scanf("%d", n);
    printf("Introdu numarul de coloane: ");
    scanf("%d", m);
    printf("Introdu numarul de triplete: ");
    scanf("%d", k);

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            mat[i][j] = 0;
        }
    }

    for (int i = 0; i < *k; i++)
    {
        scanf("%d", &xy[i].val);
        scanf("%d", &xy[i].xPos);
        scanf("%d", &xy[i].yPos);
        mat[xy[i].xPos][xy[i].yPos] = xy[i].val;
    }

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void afisareOriginala(int n, int m, int mat[][10])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void afisareDiagonale(int n, int m, int mat[][10])
{
    if (n == m)
    {
        printf("Diag principala: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d, ", mat[i][i]);
        }

        printf("\nDiag secundara: ");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i + j == n - 1)
                    printf("%d, ", mat[i][j]);
            }
        }
    }
    else
    {
        printf("Nu se poate face afisarea diagonalelor!\n");
    }
    printf("\n");
}

void construireSir(int n, int m, int mat[][10], int sir[], int fr[], int maxx)
{
    for (int j = 0; j < m; j++)
    {
        sir[j] = 0;
        for(int i = 0; i < n; i++)
        {
            sir[j] += mat[i][j];
        }
        if (sir[j] > maxx)
            maxx = sir[j];
        fr[sir[j]]++;
    }

    for (int i = 0; i < m; i++)
        printf("%d ", sir[i]);

    printf("\n");

    /*
    0 1 2 3 4 5 6 7 8
    1 1 1 3 1 0 0 0 0

    4 2 3 0 1 3 3
    */
}

void afisareSir(int m, int sir[], int fr[], int maxx)
{
    printf("\nsirul simplificat este: ");
    for (int i = 0; i < 10; i++)
        if(fr[i] != 0)
        {
            printf("%d ", i);
        }
}

void calculareMaximale(int n, int m, int mat[][10])
{
    int pozi, pozj;
    for (int i = 0; i < n; i++)
    {
        int pozS = -1, pozD, lung, lungMax = 0;
        lung = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != 0)
            {
                lung++;
                if (pozS == -1)
                    pozS = j;
                pozD = j;
            }
            else
            {
                if (lung > lungMax)
                {
                    lungMax = lung;
                    pozi = pozS;
                    pozj = pozD;
                }
                pozS = -1;
                lung = 0;
            }
        }
        if (lung > lungMax)
        {
            lungMax = lung;
            pozi = pozS;
            pozj = pozD;
        }
        if (lungMax == 0)
        {
            printf("(-)");
        }
        else
        for (int k = pozi; k <= pozj; k++)
        {
            printf("%d ", mat[i][k]);
        }
        printf("\n");

    }
}

void matriciCompacte(int n, int m, int mat[][10])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (mat[i][j] != 0)
            {
                if (mat[i][j+1] != 0 && mat[i + 1][j] != 0)
                    printf("(%d, %d), (%d, %d), (%d, %d);\n",
                            i, j, i, j+1, i+1, j);
            }
        }
    }
}

void infoAutor()
{
    printf("\nProgramul a fost realizat de toata specializarea de calculatoare.");

}
//1 3 0
//2 1 2
//0 0 0

/*
1 0 0
3 0 1
2 1 0
3 2 1
1 1 1
2 1 2
*/
