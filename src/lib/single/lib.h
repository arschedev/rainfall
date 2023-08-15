/**
 * @author arschedev
*/

typedef void* any;

#include <stdlib.h>
#include <string.h>

#define CHAR_BUFFER 2

typedef char* String;
typedef char** StringArray;
typedef char*** StringArray2D;

void ctos(char ch, String dest) {
    dest[0] = ch;
    dest[1] = '\0';
}

void concat(String a, String b, String dest) {
    strcpy(dest, a);
    strcat(dest, b);
}

#include <stdio.h>
// #include "strings.h"

void setConsoleTitle(String title) {
    printf("\033]0;%s\007", title);
}

void defaultClearConsole() {
    printf("\033[H");
}

void hideConsoleCursor() {
    printf("\033[?25l");
}

void showConsoleCursor() {
    printf("\033[?25h");
}

void pauseConsole() {
    fflush(stdout);
    while (getchar() != '\n') continue;
}

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

#include <stdio.h>
// #include "strings.h"

#define ANSI_COLOR_BLACK "\033[30m"
#define ANSI_COLOR_RED "\033[31m"
#define ANSI_COLOR_GREEN "\033[32m"
#define ANSI_COLOR_YELLOW "\033[33m"
#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_MAGENTA "\033[35m"
#define ANSI_COLOR_CYAN "\033[36m"
#define ANSI_COLOR_WHITE "\033[37m"

#define ANSI_COLOR_BLACK_BOLD "\033[1;30m"
#define ANSI_COLOR_RED_BOLD "\033[1;31m"
#define ANSI_COLOR_GREEN_BOLD "\033[1;32m"
#define ANSI_COLOR_YELLOW_BOLD "\033[1;33m"
#define ANSI_COLOR_BLUE_BOLD "\033[1;34m"
#define ANSI_COLOR_MAGENTA_BOLD "\033[1;35m"
#define ANSI_COLOR_CYAN_BOLD "\033[1;36m"
#define ANSI_COLOR_WHITE_BOLD "\033[1;37m"

#define ANSI_COLOR_LIGHT_BLACK "\033[90m"
#define ANSI_COLOR_LIGHT_RED "\033[91m"
#define ANSI_COLOR_LIGHT_GREEN "\033[92m"
#define ANSI_COLOR_LIGHT_YELLOW "\033[93m"
#define ANSI_COLOR_LIGHT_BLUE "\033[94m"
#define ANSI_COLOR_LIGHT_MAGENTA "\033[95m"
#define ANSI_COLOR_LIGHT_CYAN "\033[96m"
#define ANSI_COLOR_LIGHT_WHITE "\033[97m"

#define ANSI_COLOR_LIGHT_BLACK_BOLD "\033[1;90m"
#define ANSI_COLOR_LIGHT_RED_BOLD "\033[1;91m"
#define ANSI_COLOR_LIGHT_GREEN_BOLD "\033[1;92m"
#define ANSI_COLOR_LIGHT_YELLOW_BOLD "\033[1;93m"
#define ANSI_COLOR_LIGHT_BLUE_BOLD "\033[1;94m"
#define ANSI_COLOR_LIGHT_MAGENTA_BOLD "\033[1;95m"
#define ANSI_COLOR_LIGHT_CYAN_BOLD "\033[1;96m"
#define ANSI_COLOR_LIGHT_WHITE_BOLD "\033[1;97m"

#define ANSI_BACKGROUND_COLOR_BLACK "\033[40m"
#define ANSI_BACKGROUND_COLOR_RED "\033[41m"
#define ANSI_BACKGROUND_COLOR_GREEN "\033[42m"
#define ANSI_BACKGROUND_COLOR_YELLOW "\033[43m"
#define ANSI_BACKGROUND_COLOR_BLUE "\033[44m"
#define ANSI_BACKGROUND_COLOR_MAGENTA "\033[45m"
#define ANSI_BACKGROUND_COLOR_CYAN "\033[46m"
#define ANSI_BACKGROUND_COLOR_WHITE "\033[47m"

#define ANSI_BACKGROUND_COLOR_LIGHT_BLACK "\033[100m"
#define ANSI_BACKGROUND_COLOR_LIGHT_RED "\033[101m"
#define ANSI_BACKGROUND_COLOR_LIGHT_GREEN "\033[102m"
#define ANSI_BACKGROUND_COLOR_LIGHT_YELLOW "\033[103m"
#define ANSI_BACKGROUND_COLOR_LIGHT_BLUE "\033[104m"
#define ANSI_BACKGROUND_COLOR_LIGHT_MAGENTA "\033[105m"
#define ANSI_BACKGROUND_COLOR_LIGHT_CYAN "\033[106m"
#define ANSI_BACKGROUND_COLOR_LIGHT_WHITE "\033[107m"

#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_BOLD "\033[1m"
#define ANSI_COLOR_SIZE 16

void dye(String string, String color, String dest) {
    concat(color, string, dest);
    concat(dest, ANSI_COLOR_RESET, dest);
}

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

#include <unistd.h>

void timeout(int ms) {
    usleep(ms * 1000);
}

void timeout_f(float ms) {
    usleep(ms * 1000);
}

#include <pthread.h>

typedef pthread_t Thread;

Thread renderer_thread;

int createThread(Thread* thread, any(*routine)(any), any arg) {
    pthread_create(thread, NULL, routine, arg);
}

void revokeThread(Thread thread) {
    if (thread == renderer_thread) showConsoleCursor();
    pthread_cancel(thread);
}

void terminateThread() {
    pthread_exit(NULL);
}

void await(Thread thread) {
    pthread_join(thread, NULL);
}

#include <stdbool.h>
// #include "matrix2d.h"
// #include "threads.h"
// #include "timeout.h"

typedef struct {
    Matrix2D matrix;
    float interval;
} Matrix2DRendererOptions;

any _Matrix2DBasicRenderer_(any arg) {
    Matrix2D* matrix = (Matrix2D*)arg;
    hideConsoleCursor();
    while (true) {
        defaultClearConsole();
        printMatrix2D(*matrix);
        timeout(10);
    }

    terminateThread();
}

any _Matrix2DRenderer_(any arg) {
    Matrix2DRendererOptions* options = (Matrix2DRendererOptions*)arg;
    hideConsoleCursor();
    while (true) {
        defaultClearConsole();
        printMatrix2D(options->matrix);
        timeout_f(options->interval);
    }

    terminateThread();
}

void Matrix2DBasicRenderer(Matrix2D* matrix) {
    createThread(&renderer_thread, _Matrix2DBasicRenderer_, matrix);
}

void Matrix2DRenderer(Matrix2DRendererOptions* options) {
    createThread(&renderer_thread, _Matrix2DRenderer_, options);
}

#include <unistd.h>
#include <sys/ioctl.h>

typedef struct {
    int width;
    int height;
    int columns;
    int rows;
} Dimensions;

Dimensions getScreenDimensions() {
    Dimensions dimensions;

    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    dimensions.width = ws.ws_col;
    dimensions.height = ws.ws_row - 1;
    dimensions.columns = dimensions.width;
    dimensions.rows = dimensions.height;

    return dimensions;
}

#include <time.h>
#include <stdlib.h>

int randomInit() {
    srand(time(NULL));
}

int randomInt(int max) {
    return rand() % (max + 1);
}

int randomIntWithin(int min, int max) {
    int range = max - min;
    return randomInt(range) + min;
}

#include <stdlib.h>
#include <signal.h>

void handleSigint(void (*handler)(int)) {
    signal(SIGINT, handler);
}

void quit() {
    showConsoleCursor();
    exit(0);
}

