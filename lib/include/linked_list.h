#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "export.h"

typedef struct Mem_Info{

    struct Mem_Info *next;
    void *ptr;
    char *file_name;
    int file_line;

} Mem_Info;

MemSafe_API int check_memory_leak();
MemSafe_API void print_allocation();
MemSafe_API void append_allocation(void *ptr, char *file, int line);
MemSafe_API int delete_allocation(void *check_ptr);


#endif