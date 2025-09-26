#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct Mem_Info{

    struct Mem_Info *next;
    struct Mem_Info *prev;
    void *ptr;
    char *file_name;
    int file_line;

} Mem_Info;

int check_memory_leak();
void print_allocation();
void append_allocation(void *ptr, char *file, int line);
int delete_allocation(void *check_ptr);


#endif