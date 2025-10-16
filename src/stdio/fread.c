#include <stdio.h>

char* fgets(char *restrict str, int count, FILE *restrict stream) {
    char *strstart = str;

    while (count--) *str++ = getc(stream);

    return strstart;
}