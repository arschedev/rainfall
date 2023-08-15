#include <stdio.h>
#include <stdlib.h>
// #include "strings.h"
// #include "colors.h"

typedef struct {
    int width;
    int height;
    StringArray matrix;
} Char2D;

Char2D createChar2D(int width, int height, char fill) {
    Char2D matrix;
    matrix.width = width;
    matrix.height = height;

    matrix.matrix = (StringArray)malloc(height * sizeof(String));
    if (matrix.matrix == NULL) {
        printf("Memory allocation for StringArray failed in createChar2D\n");
        return matrix;
    }

    for (int row = 0; row < height; row++) {
        matrix.matrix[row] = (String)malloc(width * sizeof(char));
        if (matrix.matrix[row] == NULL) {
            printf("Memory allocation for String failed in createChar2D\n");
            for (int i = 0; i < row; i++) free(matrix.matrix[i]);
            free(matrix.matrix);
            matrix.matrix = NULL;
            return matrix;
        }

        for (int col = 0; col < width; col++) {
            matrix.matrix[row][col] = fill;
        }
    }

    return matrix;
}

char getCellAtChar2D(Char2D matrix, int x, int y) {
    return matrix.matrix[y][x];
}

void fillChar2D(Char2D matrix, int x, int y, char fill) {
    matrix.matrix[y][x] = fill;
}

void printChar2D(Char2D matrix) {
    for (int row = 0; row < matrix.height; row++) {
        for (int col = 0; col < matrix.width; col++) {
            printf("%c", matrix.matrix[row][col]);
        }

        printf("\n");
    }
}

void printColorizedChar2D(Char2D matrix, String color) {
    for (int row = 0; row < matrix.height; row++) {
        for (int col = 0; col < matrix.width; col++) {
            char current[CHAR_BUFFER];
            ctos(matrix.matrix[row][col], current);
            char colorized[ANSI_COLOR_SIZE];
            dye(current, color, colorized);
            printf("%s", colorized);
        }

        printf("\n");
    }
}

void freeChar2D(Char2D matrix) {
    for (int row = 0; row < matrix.height; row++) {
        free(matrix.matrix[row]);
    }

    free(matrix.matrix);
}
