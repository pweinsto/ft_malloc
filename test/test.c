#include "ft_malloc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(void)
{
    void *tiny[100];
    void *small[100];
    void *large[100];

    
    show_alloc_mem();
    
    for (int i = 0; i < 2; i++) {
        tiny[i] = ft_malloc(20);
        memcpy(tiny[i], "Hello World!", 20);
    }

    for (int i = 0; i < 2; i++) {
        small[i] = ft_malloc(200);
        memcpy(small[i], "Hello World!", 20);
    }

    for (int i = 0; i < 2; i++) {
        large[i] = ft_malloc(2000);
        memcpy(large[i], "Hello World!", 20);
    }

    show_alloc_mem();

    for (int i = 0; i < 2; i++) {
        ft_free(tiny[i]);
    }

    for (int i = 0; i < 2; i++) {
        ft_free(small[i]);
    }

    for (int i = 0; i < 2; i++) {
        ft_free(large[i]);
    }

    show_alloc_mem();

    return 0;
}