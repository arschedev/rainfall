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
