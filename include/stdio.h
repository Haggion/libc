#pragma once

#define EOF -1
#define NULL 0

#include <specific/filedefs.h>

int getchar(void);
int fgetc(FILE* stream);
int getc(FILE* stream);

int putchar(int ch);
int puts(const char* str);
int printf(const char *restrict format, ...);

char* fgets(char* restrict str, int count, FILE* restrict stream);

FILE *fopen(const char *restrict path, const char *restrict mode);