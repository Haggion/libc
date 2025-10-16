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
    if(stdin->unread) goto pop_buf;
    char ch;

    while ((ch = __sys_getchar()) != 13) {
        stdin->buf[stdin->write_pos] = ch;
        stdin->write_pos = (stdin->write_pos + 1) % stdin->bufsize;
        stdin->unread++;

        putchar(ch);
    }

    puts ("");

pop_buf:
    ch = stdin->buf[stdin->read_pos];
    stdin->read_pos = (stdin->read_pos + 1) % stdin->bufsize;
    stdin->unread--;

    return ch;
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