#include <specific/kstorage.h>

typedef void                 (*__sys_read_block_fn)(unsigned, char dest[BLOCK_SIZE]);
typedef void                 (*__sys_write_block_fn)(unsigned, char*);
typedef struct search_result (*__sys_get_file_metadata_fn)(const char*);

#define ADDR___SYS_READ_BLOCK        0x850000A8
#define ADDR___SYS_WRITE_BLOCK       0x850000B4
#define ADDR___SYS_GET_FILE_METADATA 0x850000C0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void __sys_read_block(unsigned address, char dest[BLOCK_SIZE]) {
    ((__sys_read_block_fn) ADDR___SYS_READ_BLOCK) (address, dest);
}

void __sys_write_block(unsigned address, char* data) {
    return ((__sys_write_block_fn) ADDR___SYS_WRITE_BLOCK) (address, data);
}

struct search_result __sys__get_file_metadata(const char* path) {
    return ((__sys_get_file_metadata_fn) ADDR___SYS_GET_FILE_METADATA) (path);
}