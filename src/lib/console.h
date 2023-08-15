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
