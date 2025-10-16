#pragma once

struct _FILE {
    unsigned address;
    char* buf;
    unsigned bufsize;
    unsigned read_pos;
    unsigned write_pos;
    unsigned unread;
};

typedef struct _FILE FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;