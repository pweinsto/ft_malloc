#include "ft_malloc.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>

int main(void)
{
    /*printf("pagesize: %d\n", getpagesize());

    struct rlimit lim;

    if (getrlimit(RLIMIT_CPU, &lim) == 0) {

        if (lim.rlim_cur == RLIM_INFINITY)
            printf("Soft limit: unlimited\n");
        else
            printf("Soft limit: %lu\n", lim.rlim_cur);

        if (lim.rlim_max == RLIM_INFINITY)
            printf("Hard limit: unlimited\n");
        else
            printf("Hard limit: %lu\n", lim.rlim_max);

    } else {
        perror("getrlimit");
    }*/

    printf("ptr: %p\n", ft_malloc(20));
    printf("ptr: %p\n", ft_malloc(200));
    printf("ptr: %p\n", ft_malloc(2000));

    printf("ptr: %p\n", ft_malloc(20));
    printf("ptr: %p\n", ft_malloc(200));
    printf("ptr: %p\n", ft_malloc(2000));

    return 0;
}