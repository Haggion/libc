#pragma once

#define EOF -1
#define NULL 0

// returns character written on success, and EOF otherwise
int getchar(void);
int putchar(int ch);
int puts(const char* str);
int printf(const char *restrict format, ...);