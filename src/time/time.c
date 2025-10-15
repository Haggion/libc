#include <haggion.h>

// for waiting a microsecond
#define ADDR__DELAY 0x85000084ull

#define USEC_PER_SEC 1000000

typedef void (*usleep_fn)(useconds_t);

unsigned int sleep(unsigned int seconds) {
    usleep(seconds * USEC_PER_SEC);
    return 0;
}

int usleep(useconds_t seconds) {
    ((usleep_fn) ADDR__DELAY) (seconds);
    return 0;
}