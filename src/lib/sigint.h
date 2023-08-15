#include <stdlib.h>
#include <signal.h>

void handleSigint(void (*handler)(int)) {
    signal(SIGINT, handler);
}

void quit() {
    showConsoleCursor();
    exit(0);
}
