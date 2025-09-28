

#ifndef MEMSAFE_H
#define MEMSAFE_H

#include "MemTrack_export.h"
#include "MemTrack_linked_list.h"
#include <string.h>
#include <stdlib.h>


MemSafe_API void safe_free(void **mem);
MemSafe_API void debug_free(void **mem, char *file, int line);
MemSafe_API void* debug_malloc(size_t size, char *file, int line);
MemSafe_API void* debug_realloc(void *mem, size_t size, char *file, int line);
MemSafe_API char* debug_strdup(const char* src, char *file, int line);


#ifdef TRACK_ALLOCATIONS

    //void *t_malloc(size_t size);
    #define t_malloc(size) debug_malloc(size, __FILE__, __LINE__)

    //void *t_realloc(void *ptr, size_t size);
    #define t_realloc(ptr, size) debug_realloc(ptr, size, __FILE__, __LINE__)

    /*
    void t_free(void **mem);
    auto NULL's pointer
    */
    #define t_free(ptr) debug_free((void**)ptr, __FILE__, __LINE__)

    //char *t_strdup(char *str);
    #define t_strdup(str) debug_strdup(str, __FILE__, __LINE__)
    
#else

    //void *t_malloc(size_t size);
    #define t_malloc(size) malloc(size)

    //void *t_realloc(void *mem, size_t size);
    #define t_realloc(ptr, size) realloc(ptr, size)

    /*
    void t_free(void **mem);
    auto NULL's pointer
    */
    #define t_free(ptr) safe_free((void**)ptr)

    //char *t_strdup(char *str);
    #define t_strdup(str)  strdup(str)


#endif


#endif