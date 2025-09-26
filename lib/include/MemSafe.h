

#ifndef MEMSAFE_H
#define MEMSAFE_H


#include "linked_list.h"
#include <string.h>
#include <stdlib.h>

void debug_free(void *memory);
void* debug_malloc(size_t size, char *file, int line);
void* debug_realloc(void *mem, size_t size, char *file, int line);
char* debug_strdup(const char* src, char *file, int line);



#ifdef TRACK_ALLOCATIONS

    //void *s_malloc(size_t size);
    #define s_malloc(size) debug_malloc(size, __FILE__, __LINE__)

    //void *s_realloc(void *ptr, size_t size);
    #define s_realloc(ptr, size) debug_realloc(ptr, size, __FILE__, __LINE__)

    //void s_free(void *ptr);
    #define s_free(ptr)    debug_free(ptr)

    //char *s_strdup(char *str);
    #define s_strdup(str)  debug_strdup(str, __FILE__, __LINE__)
    

#else

    //void *s_malloc(size_t size);
    #define s_malloc(size) malloc(size)

    //void *s_realloc(void *ptr, size_t size);
    #define s_realloc(ptr, size) realloc(ptr, size)

    //void s_free(void *ptr);
    #define s_free(ptr)    free(ptr)

    //char *s_strdup(char *str);
    #define s_strdup(str)  strdup(str)


#endif


#endif