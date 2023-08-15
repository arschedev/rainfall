#include <string.h>
// #include "lib/lib.h"

char randomChar() {
    char chars[] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; // 94
    return chars[randomInt(strlen(chars) - 1)];
}
