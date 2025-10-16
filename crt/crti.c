int main();

#include <specific/filedefs.h>
#include <specific/kmem.h>

FILE *stdin;
FILE *stdout;
FILE *stderr;

void crt_init(void) {
    malloc(1024 * 64);
    stdin = malloc(sizeof(FILE));

    stdin->read_pos  = 0;
    stdin->write_pos = 0;
    stdin->unread    = 0;
    stdin->buf       = malloc(4096);
    stdin->bufsize   = 4096;

    main();
}