#include <ctype.h>

int atoi(const char *nptr) {
    int result = 0;
    int mult = 1;

    char ch = *nptr;

    if (ch == '-') {
        mult = -1;
        nptr++;
    } else if (ch == '+') {
        nptr++;
    }

    while (isdigit(ch = *nptr++)) {
        result *= 10;
        result += ch - '0';
    }

    return result * mult;
}