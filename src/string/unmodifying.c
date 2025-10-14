#include <sys/types.h>

size_t strlen(const char *s) {
    size_t length = 0;

    while (0 != *s++) length++;

    return length;
}

int strcmp(const char *s1, const char *s2) {
    char ch1, ch2;

    while((ch1 = *s1++) != 0 && (ch2 = *s2++) != 0 && ch1 == ch2);

    return ch1 - ch2;
}