#include <sys/types.h>

char *strcat(char *restrict dest, const char *restrict src) {
    char *strstart = dest;

    // get end of dest
    while (*dest != 0) dest++;

    // append src to dest
    while (*src != 0) {
        *dest = *src;
        src++;
        dest++;
    }

    // end dest with null terminator
    *dest = 0;

    return strstart;
}

char *strncat(char *restrict dest, const char *restrict src, size_t n) {
    char *strstart = dest;

    // get end of dest
    while (*dest != 0) dest++;

    // append src up to n to dest
    while (*src != 0 && 0 < n--) {
        *dest = *src;
        src++;
        dest++;
    }

    // end dest with null terminator
    *dest = 0;

    return strstart;
}