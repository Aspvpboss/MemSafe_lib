#include <stdlib.h>
#include <string.h>
#include "linked_list.h"


void debug_free(void *memory){

    if(memory){
        delete_allocation(memory);
        free(memory);
    }
    
}


void* debug_malloc(size_t size, char *file, int line){

    void *mem = malloc(size);

    if(mem){
        append_allocation(mem, file, line);
    }

    return mem;
}


void* debug_realloc(void *mem, size_t size, char *file, int line){

    if(!mem)
        return debug_malloc(size, file, line);


    delete_allocation(mem);
    
    void *new_mem = realloc(mem, size);
    if(new_mem)
        append_allocation(new_mem, file, line);


    return new_mem;

}

char* debug_strdup(const char* src, char *file, int line){
    size_t src_len = strlen(src);
    char *dup = NULL;

    dup = debug_malloc(sizeof(char) * (src_len + 1), file, line);
    strcpy(dup, src);
    dup[src_len] = '\0';

    return dup;
}