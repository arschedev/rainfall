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
