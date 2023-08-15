#include <unistd.h>

void timeout(int ms) {
    usleep(ms * 1000);
}

void timeout_f(float ms) {
    usleep(ms * 1000);
}
