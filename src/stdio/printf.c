#include <stdio.h>

int printf(const char *restrict format, ...) {
    char ch;
    while ((ch = *format++) != NULL){
        putchar (ch);
    }

    return 0;
}