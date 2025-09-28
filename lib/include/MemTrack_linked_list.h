#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "MemTrack_export.h"
#include <stddef.h>

typedef struct Mem_Info{

    struct Mem_Info *next;
    size_t size;
    void *ptr;
    char *file_name;
    int file_line;

} Mem_Info;

MemSafe_API size_t check_memory_usage();
MemSafe_API void print_tracking_info();
MemSafe_API void free_tracking_info();
MemSafe_API int check_memory_leak();
MemSafe_API int append_allocation(void *ptr, char *file, int line, size_t size);
MemSafe_API int delete_allocation(void *check_ptr);


#endif