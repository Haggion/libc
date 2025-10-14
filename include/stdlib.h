#pragma once

#include <sys/types.h>

void *malloc(size_t size);
void free(void *pointer);

int atoi(const char *nptr);
char *itoa(int value, char *str, int base);