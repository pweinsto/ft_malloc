#include "../inc/ft_malloc.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <sys/mman.h>

t_zone	*g_zones[3] = {NULL, NULL, NULL};

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
		return (round_up_page((ZONE_OVERHEAD + BLOCK_OVERHEAD + size)));
}

void push_zone(t_zone **head, t_zone *zone)
{
	zone->prev = NULL;
	zone->next = *head;
	if (*head)
		(*head)->prev = zone;
	*head = zone;
}

static void *block_to_payload(t_block *block)
{
	return ((void *)((char *)block + BLOCK_OVERHEAD));
}

void *create_zone(t_zone_type type, size_t size)
{
	void 	*mem;
	size_t	map_length;
	t_zone	*zone;
	t_block	*first;

	map_length = calc_zone_size(type, size);

	mem = mmap(NULL, map_length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	zone = (t_zone *)mem;
	zone->map_length = map_length; 
	zone->type = type;
	zone->prev = NULL;
	zone->next = NULL;

	first = (t_block *)((char *)mem + ZONE_OVERHEAD);
	first->size = map_length - ZONE_OVERHEAD - BLOCK_OVERHEAD;
	first->free = 1;
	first->zone = zone;
	first->prev = NULL;
	first->next = NULL;

	zone->first = first;

	return (zone);
}

t_block *find_fit(t_zone *zones, size_t size)
{
	t_block	*block;

	while (zones)
	{
		block = zones->first;
		while (block)
		{
			if (block->free && block->size >= size)
				return block;
			block = block->next;		
		}
		zones = zones->next;
	}

	return (NULL);
}

void split_block(t_block *block, size_t size)
{
	t_block	*new_block;

	size_t rest;

	if (block->size <= size + BLOCK_OVERHEAD + ALIGNMENT)
		return ;
	rest = block->size - size - BLOCK_OVERHEAD;
	new_block = (t_block *)((char *)block_to_payload(block) + size);
	new_block->size = rest;
	new_block->free = 1;
	new_block->zone = block->zone;
	new_block->prev = block;
	new_block->next = block->next;
	if (block->next)
		block->next->prev = new_block;
	block->next = new_block;
	block->size = size;
}

void *ft_malloc(size_t size)
{
	t_zone_type	type;
	t_zone		*zone;
	t_block		*block;

	zone = NULL;
	block = NULL;
	
	size = ALIGN_UP(size);

	if (size <= TINY_MAX)
		type = TINY;
	else if (size <= SMALL_MAX)
		type = SMALL;
	else
		type = LARGE;

	
	if (type == LARGE)
	{
		zone = create_zone(type, size);
		push_zone(&g_zones[type], zone);

		block = zone->first;
		block->free = 0;

		return block_to_payload(block);
	}
	
	block = find_fit(g_zones[type], size);
	
	if (!block)
	{
		zone = create_zone(type, size);
		push_zone(&g_zones[type], zone);
		block = zone->first;
	}

	split_block(block, size);
	block->free = 0;

	return (block_to_payload(block));
}