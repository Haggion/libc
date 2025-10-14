#include <sys/types.h>
#include <syscall.h>

#define ADDR__MALLOC 0x85000090
#define ADDR__FREE   0x8500009C

void *malloc(size_t size) {
    SYSCALL(ADDR__MALLOC)
}

void free(void *pointer) {
    SYSCALL(ADDR__FREE)
}