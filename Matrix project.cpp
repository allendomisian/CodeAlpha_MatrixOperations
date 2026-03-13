#include <stdio.h>

void inputMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[10][10], int b[10][10], int r, int c) {
    int sum[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nResult of Matrix Addition:\n");
    displayMatrix(sum, r, c);
}

void multiplyMatrices(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int prod[10][10];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("\nResult of Matrix Multiplication:\n");
    displayMatrix(prod, r1, c2);
}

void transposeMatrix(int a[10][10], int r, int c) {
    int trans[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            trans[j][i] = a[i][j];
        }
    }
    printf("\nTranspose of the Matrix:\n");
    displayMatrix(trans, c, r);
}

int main() {
    int mat1[10][10], mat2[10][10];
    int rows, cols, r2, c2;

    printf("--- CodeAlpha Matrix Operations ---\n");
    printf("Enter rows and columns for Matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("\nInput Matrix A:\n");
    inputMatrix(mat1, rows, cols);

    transposeMatrix(mat1, rows, cols);

    printf("\nInput Matrix B (for Addition/Multiplication):\n");
    inputMatrix(mat2, rows, cols);

    addMatrices(mat1, mat2, rows, cols);

    multiplyMatrices(mat1, mat2, rows, cols, cols);

    return 0;
}
