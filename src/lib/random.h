#include <time.h>
#include <stdlib.h>

void randomInit() {
    srand(time(NULL));
}

int randomInt(int max) {
    return rand() % (max + 1);
}

int randomIntWithin(int min, int max) {
    int range = max - min;
    return randomInt(range) + min;
}
