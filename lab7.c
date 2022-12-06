#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix( int n,  int m, int matrix[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d\t ",matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(int n, int m, int matrix[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] = rand() %10 + 1;
        }
    }
}

void computeSumsOfTriangles(int n, int m, int matrix[n][m],int* upperSum, int* lowerSum){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (i < j) {
                *upperSum += matrix[i][j];
            }
            if (i > j) {
                *lowerSum += matrix [i][j];
            }
        }
    }
}
void compareAndReflect(int upperSum, int lowerSum, int n, int m, int matrix[n][m]){
    if (lowerSum<upperSum){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                matrix[j][i] = matrix[i][j];
                                }
            }
    printf("Upper sum = %d\n", lowerSum);
    printf("Lower sum = %d\n", upperSum);
    printf("Upper sum\n");
    }
    
    if (upperSum<lowerSum){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                matrix[i][j] = matrix[j][i];
                
                }
        }
    printf("Lower sum = %d\n", upperSum);
    printf("Upper sum = %d\n", lowerSum);
    printf("Lower sum\n");
    }

}

int main()
{
    srand(time(NULL));
    int n;
    int m;
    printf("Введите размерность матрицы -> \n");
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    fillMatrix(n,m,matrix);
    printf("Исходная матрица\n");
    printMatrix(n, m, matrix);
    printf("\n");
    int upperSum = 0;
    int lowerSum = 0;
    computeSumsOfTriangles(n, m, matrix, &upperSum, &lowerSum);
    compareAndReflect(upperSum, lowerSum, n, m, matrix);
    printf("Симметричная матрица\n");
    printMatrix(n, m, matrix);
    return 0;
}