#include "../inc/ft_malloc.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <sys/mman.h>

size_t	round_up_page(size_t size)
{
	size_t	ps;

	ps = getpagesize();
	return (((size + ps - 1) / ps) * ps);
}

size_t calc_zone_size(t_zone_type type, size_t size)
{
	if (type == TINY)
		return (round_up_page(ZONE_OVERHEAD + ALLOCATIONS * (BLOCK_OVERHEAD + TINY_MAX)));
	else if (type == SMALL)
		return (round_up_page(ZONE_OVERHEAD + ALLOCATIONS * (BLOCK_OVERHEAD + SMALL_MAX)));
	else
		return round_up_page((ZONE_OVERHEAD + BLOCK_OVERHEAD + size));
}

void *create_zone(t_zone_type type, size_t size)
{
	void 	*mem;
	size_t	map_length;

	map_length = calc_zone_size(type, size);

	mem = mmap(NULL, map_length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	return mem;
}

void *ft_malloc(size_t size)
{
	void *ptr;
	t_zone_type	type;

	size = ALIGN_UP(size);

	if (size <= TINY_MAX)
		type = TINY;
	else if (size <= SMALL_MAX)
		type = SMALL;
	else
		type = LARGE;


	
	ptr = create_zone(type, size);

	
	return ptr;
}