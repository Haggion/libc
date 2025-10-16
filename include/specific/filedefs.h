#pragma once

typedef int (*read_next_fn) (void);

struct _FILE {
    unsigned address;

    char* buf;
    unsigned bufsize;

    unsigned read_pos;
    unsigned write_pos;

    unsigned unread;

    read_next_fn read_next;
};



typedef struct _FILE FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;