#define TRACK_ALLOCATIONS

#include "MemSafe.h"
#include <stdio.h>


int main(void){

    int *array = s_malloc(sizeof(int) * 10);
    char *string = s_strdup("burger");

    array[2] = 1;

    printf("%s\n", string);

    if(check_memory_leak())
        print_allocation();
    

    s_free(array);

    if(check_memory_leak())
        print_allocation();


    printf("%zu\n", sizeof(Mem_Info));
    



    return 0;
}