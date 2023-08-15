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
