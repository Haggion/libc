#include <stdio.h>

char* fgets(char *restrict str, int count, FILE *restrict stream) {
    char *strstart = str;

    while ((*str++ = getc(stream)) != '\r' && --count);
    *str++ = 0;

    return strstart;
}