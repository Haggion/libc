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

char *itoa(int value, char *str, int base) {
    char *strstart;
    if (value == 0) {
        *str = '0';
        *++str = 0;
        return strstart;
    }
    
    unsigned digits = 0;
    int temp = value;
    int mult = 1;

    if (value < 0) mult = -1;

    while (temp > 0) {
        temp /= base;
        digits++;
    }

    temp = value;
    char buf[digits];
    for (int i = digits - 1; i >= 0; i--) {
        buf[i] = temp % base + '0';
        temp /= base;
    }

    for (int i = 0; i < digits; i++) {
        *str = buf[i];
        str++;
    }

    *str = 0;

    return strstart;
}