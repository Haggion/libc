#define ADDR__PUT_CHAR 0x8500000C
#define ADDR__GET_CHAR 0x85000030

#include <syscall.h>
#include <stdio.h>

int getchar(void) {
    SYSCALL(ADDR__GET_CHAR)
}

int putchar(int ch) {
    SYSCALL(ADDR__PUT_CHAR)
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