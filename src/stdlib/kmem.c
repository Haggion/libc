#include <sys/types.h>

#define ADDR__MALLOC 0x85000090ull
#define ADDR__FREE   0x8500009Cull

typedef void *(*malloc_fn)(size_t);
typedef void (*free_fn)(void*);

void *malloc(size_t size) {
    return ((malloc_fn) ADDR__MALLOC) (size);
}

void free(void *pointer) {
    ((free_fn) ADDR__FREE) (pointer);
}