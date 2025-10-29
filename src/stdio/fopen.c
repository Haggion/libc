#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <specific/kstorage.h>
#include <specific/sysio.h>

FILE *fopen(const char *restrict path, const char *restrict mode) {
    struct search_result result = __sys__get_file_metadata(path);

    char attributes = 0;

    if      (strcmp(mode, "r")  == 0)  attributes = R;
    else if (strcmp(mode, "w")  == 0)  attributes = W;
    else if (strcmp(mode, "a")  == 0)  attributes = A;
    else if (strcmp(mode, "r+") == 0) attributes = R | W;
    else if (strcmp(mode, "w+") == 0) attributes = R | W;
    else if (strcmp(mode, "a+") == 0) attributes = R | A;
    else return NULL;

    if (!result.found_result) return NULL;

    FILE* file = malloc(sizeof(FILE));

    file->metadata   = result.file;
    file->unread     = 0;
    file->read_pos   = 0;
    file->write_pos  = attributes & A ? result.file.data_start : 0;
    file->buf        = malloc(1024);
    file->bufsize    = 1024;
    file->address    = result.address;
    file->read_addr  = result.file.data_start;
    file->write_addr = result.file.data_start;
    file->attributes = attributes;
    file->read_next  = standard_file_read_char;

    return file;
}