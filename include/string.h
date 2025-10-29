#pragma once

#include <sys/types.h>

size_t strlen(const char *s);
int strcmp(const char *s1, const char *s2);

char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

void* memcpy(void* dest, const void* src, size_t count);