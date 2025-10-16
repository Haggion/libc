#define ADDR__PUT_CHAR 0x8500000Cull
#define ADDR__GET_CHAR 0x85000030ull

#include <stdio.h>

// the way the OS getchar and libc getchar
// functions work differs quite a bit
// The OS getchar just returns the character typed

typedef int (*getchar_fn)(void);
typedef int (*putchar_fn)(int);

int __sys_getchar(void) {
    char ch = ((getchar_fn) ADDR__GET_CHAR) ();

    if(ch == 13) {
        puts ("");
        return EOF;
    }

    // people like to see what they're typing
    putchar(ch);
    return ch;
}

int getchar(void) {
    return getc(stdin);
}

int fgetc(FILE* stream) {
    return getc(stream);
}

int getc(FILE* stream) {
    if(stream->unread) goto pop_buf;
    char ch;

    while ((ch = (stream->read_ch)()) != (char) EOF) {
        stream->buf[stream->write_pos] = ch;
        stream->write_pos = (stream->write_pos + 1) % stream->bufsize;
        stream->unread++;
    }

    if(!stream->unread) return -1;

pop_buf:
    ch = stream->buf[stream->read_pos];
    stream->read_pos = (stream->read_pos + 1) % stream->bufsize;
    stream->unread--;

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