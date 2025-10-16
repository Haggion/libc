#pragma once

#define EOF -1
#define NULL 0

#include <specific/filedefs.h>

// returns character written on success, and EOF otherwise
int getchar(void);
int putchar(int ch);
int puts(const char* str);
int printf(const char *restrict format, ...);

char* fgets(char* restrict str, int count, FILE* restrict stream);