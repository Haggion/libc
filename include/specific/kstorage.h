#pragma once

#define BLOCK_SIZE 512

void __sys_read_block(unsigned address, char dest[BLOCK_SIZE]);
void __sys_write_block(unsigned address, char* data);

struct link {
    unsigned address;
    char link_type;
};

struct file_metadata {
    char name[32];
    char attributes;
    char time_was_created;
    char date_was_created;
    unsigned size;
    char num_links;
    unsigned data_start;
    struct link links[94];
};

struct search_result {
    struct file_metadata file;
    unsigned address;
    char found_result;
};

struct search_result __sys__get_file_metadata(const char* path);