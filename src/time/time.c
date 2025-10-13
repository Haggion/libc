#include <haggion.h>
#include <syscall.h>

// for waiting a microsecond
#define ADDR__DELAY 0x85000084

#define USEC_PER_SEC 1000000

unsigned int sleep(unsigned int seconds) {
    usleep(seconds * USEC_PER_SEC);
    return 0;
}

int usleep(useconds_t seconds) {
    SYSCALL(ADDR__DELAY)
    return 0;
}