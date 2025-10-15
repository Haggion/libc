#define ADDR__PUT_CHAR 0x8500000Cull
#define ADDR__GET_CHAR 0x85000030ull

#include <stdio.h>

// the way the OS getchar and libc getchar
// functions work differs quite a bit
// The OS getchar just returns the character typed

typedef int (*getchar_fn)(void);
typedef int (*putchar_fn)(int);

int __sys_getchar(void) {
    return ((getchar_fn) ADDR__GET_CHAR) ();
}

int getchar(void) {
}

int putchar(int ch) {
    return ((putchar_fn) ADDR__PUT_CHAR) (ch);
}

int puts(const char* str){
    char ch;
    while ((ch = *str++) != NULL){
        putchar (ch);
    }

    putchar ('\n');
    putchar ('\r');

    return 0;
}