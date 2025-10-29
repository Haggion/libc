#pragma once

#include <specific/kstorage.h>

#define R 0b0001
#define W 0b0010
#define A 0b0100
#define B 0b1000

struct _FILE;

typedef int (*read_next_fn) (struct _FILE*);

struct _FILE {
    unsigned address;

    char* buf;
    unsigned bufsize;

    unsigned read_pos;
    unsigned write_pos;

    unsigned read_addr;
    unsigned write_addr;

    unsigned unread;

    read_next_fn read_next;

    struct file_metadata metadata;

    char attributes;
};

typedef struct _FILE FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;