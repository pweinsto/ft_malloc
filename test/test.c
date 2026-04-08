#include "ft_malloc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(void)
{
    void *ptrs[100];

    
    show_alloc_mem();
    
    for (int i = 0; i < 100; i++) {
        ptrs[i] = ft_malloc(20);
        memcpy(ptrs[i], "Hello World!", 20);
    }

    show_alloc_mem();

    for (int i = 0; i < 98; i++) {
        ft_free(ptrs[i]);
    }

    ft_free(ptrs[98]);
    ft_free(ptrs[99]);

    show_alloc_mem();

    return 0;
}