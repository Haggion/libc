#define ADDR__PUT_CHAR 0x8500000Cull
#define ADDR__GET_CHAR 0x85000030ull

#include <stdio.h>

// the way the OS getchar and libc getchar
// functions work differs quite a bit
// The OS getchar just returns the character typed

typedef int (*getchar_fn)(void);
typedef int (*putchar_fn)(int);

int __sys_getchar(void) {
    getchar_fn read = ((getchar_fn) ADDR__GET_CHAR);
    char ch;

    do {
        ch = read();
        putchar (ch);

        stdin->buf[stdin->write_pos] = ch;
        stdin->write_pos = (stdin->write_pos + 1) % stdin->bufsize;
        stdin->unread++;
    } while (ch != '\r');

    if(!stdin->unread) return EOF;

    return stdin->unread;
}

int getchar(void) {
    return getc(stdin);
}

int fgetc(FILE* stream) {
    return getc(stream);
}

int getc(FILE* stream) {
    if(stream->unread) goto pop_buf;
    
    if(stream->read_next() == EOF) return EOF;

pop_buf:
    const char ch = stream->buf[stream->read_pos];
    stream->read_pos = (stream->read_pos + 1) % stream->bufsize;
    stream->unread--;

    return ch;
}

int putchar(int ch) {
    if (ch == '\r' || ch == '\n') {
        ((putchar_fn) ADDR__PUT_CHAR) ('\n');
        return ((putchar_fn) ADDR__PUT_CHAR) ('\r');
    }
    return ((putchar_fn) ADDR__PUT_CHAR) (ch);
}

int puts(const char* str){
    char ch;
    while ((ch = *str++) != NULL){
        putchar (ch);
    }

    putchar ('\r');

    return 0;
}