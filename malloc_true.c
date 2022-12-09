#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail()
{
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

void printMatrix(int n, int m, int *matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t ", matrix[i * m + j]);
        }
        printf("\n");
    }
}

void fillMatrix(int n, int m, int *matrix)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i * m + j] = rand() % 100 + 1;
}

void computeSumsOfTriangles(int n, int m, int *matrix, int *upperSum, int *lowerSum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < j)
            {
                *upperSum += matrix[i * m + j];
            }
            if (i > j)
            {
                *lowerSum += matrix[i * m + j];
            }
        }
    }
}
void compareAndReflect(int upperSum, int lowerSum, int n, int m, int *matrix)
{
    if (lowerSum < upperSum)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j * n + i] = matrix[i * m + j];
            }
        }
    printf("Upper sum = %d\n", lowerSum);
    printf("Lower sum = %d\n", upperSum);
    printf("Upper sum\n");
    }
    if (upperSum < lowerSum)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i * m + j] = matrix[j * n + i];
            }
        }
    }
    printf("Lower sum = %d\n", upperSum);
    printf("Upper sum = %d\n", lowerSum);
    printf("Lower sum\n");
    }

int main()
{
    srand(time(NULL));
    int n;
    int m;
    printf("Введите размерность матрицы -> \n");
    scanf("%d %d", &n, &m);
    // printf("\n");

    int *matrix = (int *)malloc(n * m * sizeof(int));
    if (!matrix)
        fail();

    fillMatrix(n, m, matrix);
    printf("Исходная матрица\n");
    printMatrix(n, m, matrix);
    printf("\n");
    int upperSum = 0;
    int lowerSum = 0;
    computeSumsOfTriangles(n, m, matrix, &upperSum, &lowerSum);
    compareAndReflect(upperSum, lowerSum, n, m, matrix);
    printf("Симметричная матрица\n");
    printMatrix(n, m, matrix);

    free(matrix);

    return 0;
}