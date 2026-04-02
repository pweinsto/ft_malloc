#include "ft_malloc.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(void)
{
    void *ptrs[100];

    for (int i = 0; i < 100; i++) {
        ptrs[i] = malloc(128);
    }

    for (int i = 0; i < 100; i++) {
        free(ptrs[i]);
    }

    return 0;
}