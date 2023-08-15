#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib/lib.h"
#include "util.h"

any init(any arg);
void sigintHandler(int signum);

typedef struct {
    Matrix2D matrix;
    int x;
} Init;

Matrix2D matrix;
Thread* threads;
Init** args;

//
int main() {
    randomInit();
    setConsoleTitle("rainfall");

    handleSigint(sigintHandler);

    Dimensions dimensions = getScreenDimensions();

    matrix = createMatrix2D(dimensions.width, dimensions.height, " ");
    if (matrix.matrix == NULL) return 1;

    Matrix2DBasicRenderer(&matrix);

    threads = (Thread*)malloc(matrix.width * sizeof(Thread));
    if (threads == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    args = (Init**)malloc(matrix.width * sizeof(Init*));
    if (args == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < matrix.width; i += 2) {
        args[i] = malloc(sizeof(Init)); //
        args[i]->matrix = matrix;
        args[i]->x = i;
        createThread(&threads[i], init, args[i]);
    }

    await(renderer_thread);

    return 0;
}

//
any init(any arg) {
    Init* args = (Init*)arg;

    int speed = randomIntWithin(35, 70);
    int maxLength = randomIntWithin(args->matrix.height / 2.5, args->matrix.height / 1.5);
    int lengthLimit = maxLength;

    String color = ANSI_COLOR_LIGHT_WHITE_BOLD;
    bool floor = false;
    char current[CHAR_BUFFER];
    int length = 0;
    int y = 0;

    timeout(randomIntWithin(1, 3000));

    while (y < args->matrix.height) {
        if (!floor && length < maxLength) length++;

        char colorized[ANSI_COLOR_SIZE];

        dye(current, ANSI_COLOR_LIGHT_GREEN_BOLD, colorized);
        if (!floor && y > 0) fillMatrix2D(args->matrix, args->x, y - 1, colorized);

        ctos(randomChar(), current);
        dye(current, color, colorized);
        fillMatrix2D(args->matrix, args->x, y, colorized);

        if (floor || length == maxLength) fillMatrix2D(args->matrix, args->x, y - (lengthLimit - 1), " ");

        y++;

        if (y == args->matrix.height) {
            floor = true;
            color = ANSI_COLOR_LIGHT_GREEN_BOLD;

            if (lengthLimit != 1) {
                lengthLimit--;
                y--;
            } else {
                floor = false;
                color = ANSI_COLOR_LIGHT_WHITE_BOLD;
                speed = randomIntWithin(35, 70);
                maxLength = randomIntWithin(args->matrix.height / 2.5, args->matrix.height / 1.5);
                lengthLimit = maxLength;
                length = 0;
                y = 0;
            }
        }

        timeout(speed);
    }
}

//
void sigintHandler(int signum) {
    revokeThread(renderer_thread);
    for (int i = 0; i < matrix.width; i += 2) {
        revokeThread(threads[i]);
        free(args[i]);
    }

    free(args);
    freeMatrix2D(matrix);
    free(threads);
    defaultClearConsole();
    printf("\nSIGINT\n");
}
