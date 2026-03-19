#include "../libft/libft.h"
#include <sys/mman.h>

void *ft_malloc(size_t size)
{
	void *ptr;
	int pagesize;


	pagesize = getpagesize();
	ft_putstr_fd("malloc\n", size);


	// LARGE

	ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	return ptr;
}