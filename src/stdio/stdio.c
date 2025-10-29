#define ADDR__PUT_CHAR 0x8500000Cull
#define ADDR__GET_CHAR 0x85000030ull

#include <stdio.h>
#include <specific/kstorage.h>

// the way the OS getchar and libc getchar
// functions work differs quite a bit
// The OS getchar just returns the character typed

typedef int (*getchar_fn)(void);
typedef int (*putchar_fn)(int);

int __sys_getchar(FILE* file) {
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

int standard_file_read_char(FILE* file) {
    if(file->read_pos >= file->metadata.size) return EOF;

    char block_bytes[512];
    __sys_read_block(file->read_addr, block_bytes);
    unsigned chars_to_read;

    // last four bytes are reserved for addr of next data block
    if(file->read_pos + BLOCK_SIZE - 4 < file->metadata.size) {
        // in case that there remains data after reading this block,
        // we want to change file to point to next data block etc.
        file->read_addr =   block_bytes[BLOCK_SIZE - 1]       +
                            block_bytes[BLOCK_SIZE - 2] << 8  +
                            block_bytes[BLOCK_SIZE - 3] << 16 +
                            block_bytes[BLOCK_SIZE - 4] << 24;
        chars_to_read = BLOCK_SIZE - 4;
    } else {
        chars_to_read  = file->metadata.size - file->read_pos;
    }

    for (int i = 0; i < chars_to_read; i++){
        file->buf[file->write_pos] = block_bytes[i];
        file->write_pos = (file->write_pos + 1) % file->bufsize;
        file->unread++;
    }

    if (!file->unread) return EOF;

    return file->unread;
}

int getchar(void) {
    return getc(stdin);
}

int fgetc(FILE* stream) {
    return getc(stream);
}

int getc(FILE* stream) {
    if(stream->unread) goto pop_buf;
    
    if(stream->read_next(stream) == EOF) return EOF;

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