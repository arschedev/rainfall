#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "strings.h"

typedef struct {
    int width;
    int height;
    StringArray2D matrix;
} Matrix2D;

Matrix2D createMatrix2D(int width, int height, String fill) {
    Matrix2D matrix;
    matrix.width = width;
    matrix.height = height;

    matrix.matrix = (StringArray2D)malloc(height * sizeof(StringArray));
    if (matrix.matrix == NULL) {
        printf("Memory allocation for StringArray2D failed in createMatrix2D\n");
        return matrix;
    }

    for (int row = 0; row < height; row++) {
        matrix.matrix[row] = (StringArray)malloc(width * sizeof(String));
        if (matrix.matrix[row] == NULL) {
            printf("Memory allocation for StringArray failed in createMatrix2D\n");

            for (int r = 0; r < row; r++) {
                for (int c = 0; c < width; c++) free(matrix.matrix[r][c]);
                free(matrix.matrix[r]);
            }

            free(matrix.matrix);
            matrix.matrix = NULL;
            return matrix;
        }

        for (int col = 0; col < width; col++) {
            matrix.matrix[row][col] = (String)malloc(255 * sizeof(char));
            if (matrix.matrix[row][col] == NULL) {
                printf("Memory allocation for String failed in createMatrix2D\n");

                for (int r = 0; r < row; r++) {
                    for (int c = 0; c < col; c++) free(matrix.matrix[r][c]);
                    free(matrix.matrix[r]);
                }

                free(matrix.matrix);
                matrix.matrix = NULL;
                return matrix;
            }

            strcpy(matrix.matrix[row][col], fill);
        }
    }

    return matrix;
}

String getCellAtMatrix2D(Matrix2D matrix, int x, int y) {
    return matrix.matrix[y][x];
}

void fillMatrix2D(Matrix2D matrix, int x, int y, String fill) {
    strcpy(matrix.matrix[y][x], fill);
}

void printMatrix2D(Matrix2D matrix) {
    for (int row = 0; row < matrix.height; row++) {
        for (int col = 0; col < matrix.width; col++) {
            printf("%s", matrix.matrix[row][col]);
        }

        printf("\n");
    }
}

void freeMatrix2D(Matrix2D matrix) {
    for (int row = 0; row < matrix.height; row++) {
        for (int col = 0; col < matrix.width; col++) free(matrix.matrix[row][col]);
        free(matrix.matrix[row]);
    }

    free(matrix.matrix);
}
