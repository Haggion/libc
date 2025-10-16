#include <stdio.h>

char* fgets_stdin(char *restrict str, int count) {
    char *strstart = str;

    while (count--) *str++ = getchar();

    return strstart;
}

char* fgets(char *restrict str, int count, FILE *restrict stream) {
    char *strstart = str;

    if(stream == stdin) return fgets_stdin(str, count);

    return strstart;
}