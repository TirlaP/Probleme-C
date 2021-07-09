#include <stdio.h>
#include <stdlib.h>

/**
    Să se scrie un program care citeşte de la tastatură două matrice:
    una inferior triunghiulară (toate elementele de deasupra diagonalei
    principale sunt nule), şi cealaltă superior triunghiulară.
    Ele vor fi reprezentate în memorie cât mai compact cu putinţă
    (fară a stoca şi zerourile de deasupra, respectiv dedesubtul
    diagonalei). Se va calcula apoi produsul celor matrice, şi
    se va afişa.
*/

void inmultireMat(int *mat1[], int *mat2[], int *mat3[], int n);
void citireMat(int *mat1[], int *mat2[], int *mat3[], int n);

int main()
{
    int n;
    scanf("%d", &n);

    int **mat1, **mat2, **mat3;

    mat1 = malloc(n * sizeof(int *));
    mat2 = malloc(n * sizeof(int *));
    mat3 = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        mat1[i] = malloc(n * sizeof(int));
        mat2[i] = malloc(n * sizeof(int));
        mat3[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                mat1[i][j] = rand() % 15;
            }
            if (i <= j)
            {
                mat2[i][j] = rand() % 16;
            }
        }
    }
    inmultireMat(mat1, mat2, mat3, n);

    printf("Matricea 1: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i >= j)
                printf("%4d", mat1[i][j]);
            else
                printf("%4d", 0);
        printf("\n");
    }

    printf("\n\n");
    printf("Matricea 2: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i <= j)
                printf("%4d", mat2[i][j]);
            else
                printf("%4d", 0);
        printf("\n");
    }

    printf("\n\n");
    printf("Matricea finala: \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", mat3[i][j]);
        printf("\n");
    }

    free(mat1);
    free(mat2);
    free(mat3);
    return 0;
}

void citireMat(int *mat1[], int *mat2[], int *mat3[], int n)
{

}


void inmultireMat(int *mat1[], int *mat2[], int *mat3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int x = 0; x < n; x++)
                if (x > i || x > j)
                    continue;
                else
                    mat3[i][j] = mat1[i][x] * mat2[x][j];
        }
    }
}
