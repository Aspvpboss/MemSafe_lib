#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "MemTrack_linked_list.h"


void safe_free(void **mem){

    if(!(*mem))
        return;

    free(*mem);
    *mem = NULL;

}

void debug_free(void **mem, char *file, int line){

    if(!file){
        printf("MemTrack ERROR: debug_free doesn't accept 'NULL' into 'char *file'\n");
        return;
    }

    if(!(*mem))
        return;

    if(delete_allocation(*mem)){
        printf("MemTrack ERROR: failed to free old tracking info for file %s, line - %d\n", file, line);
        return;
    }
    free(*mem);
    *mem = NULL;
    
}


void* debug_malloc(size_t size, char *file, int line){

    if(!file){
        printf("MemTrack ERROR: debug_free doesn't accept 'NULL' into 'char *file'\n");
        return NULL;
    }

    void *mem = malloc(size);
    if(!mem){
        printf("MemTrack ERROR: failed to malloc for file %s, line - %d\n", file, line);
        return NULL;
    }

    if(append_allocation(mem, file, line, size)){
        free(mem);
        printf("MemTrack ERROR: failed to malloc tracking info for file %s, line - %d\n", file, line);
        return NULL;    
    }

    return mem;
}


void* debug_realloc(void *mem, size_t size, char *file, int line){

    if(!file){
        printf("MemTrack ERROR: debug_free doesn't accept 'NULL' into 'char *file'\n");
        return NULL;
    }


    if(!mem)
        return debug_malloc(size, file, line);

    if(delete_allocation(mem)){
        printf("MemTrack ERROR: failed to free old tracking info for file %s, line - %d\n", file, line);
        return NULL;
    }
    
    void *new_mem = realloc(mem, size);

    if(!new_mem){
        printf("MemTrack ERROR: failed to realloc for file %s, line - %d\n", file, line);
        return NULL;
    }

    if(append_allocation(new_mem, file, line, size)){
        free(new_mem);
        printf("MemTrack ERROR: failed to malloc tracking info for file %s, line - %d\n", file, line);
        return NULL;            
    }


    return new_mem;
}

char* debug_strdup(const char* src, char *file, int line){

    if(!file){
        printf("MemTrack ERROR: debug_free doesn't accept 'NULL' into 'char *file'\n");
        return NULL;
    }

    if(!src){
        printf("MemTrack ERROR: debug_strdup doesn't accept 'NULL' into 'char *src' for file %s, line - %d\n", file, line);
        return NULL;
    }

    size_t src_len = strlen(src);

    char *dup = debug_malloc(sizeof(char) * (src_len + 1), file, line);
    if(!dup)
        return NULL;

    strcpy(dup, src);
    dup[src_len] = '\0';

    return dup;
}