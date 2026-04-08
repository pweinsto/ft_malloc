#include "../inc/ft_malloc.h"
#include <sys/mman.h>

t_block *payload_to_block(void *ptr)
{
	return ((t_block *)((char *)ptr - BLOCK_OVERHEAD));
}

void unlink_zone(t_zone **head, t_zone *zone)
{
	if (zone->prev)
		zone->prev->next = zone->next;
	else
		*head = zone->next;

	if (zone->next)
		zone->next->prev = zone->prev;
}

void merge_with_next(t_block *block)
{
	t_block *next;

	next = block->next;
	if (!next || !next->free)
		return ;
	block->size += BLOCK_OVERHEAD + next->size;
	block->next = next->next;
	if (block->next)
		block->next->prev = block;
}

t_block *merge_blocks(t_block *block)
{
	if (block->prev && block->prev->free)
	{
		block = block->prev;
		merge_with_next(block);
	}
	while (block->next && block->next->free)
		merge_with_next(block);
	return (block);
}

int zone_is_empty(t_zone *zone)
{
	t_block *first;

	first = zone->first;
	if (!first)
		return (0);
	return (
		first->free
		&& first->prev == NULL
		&& first->next == NULL
		&& first->size == zone->map_length - ZONE_OVERHEAD - BLOCK_OVERHEAD);
}

void destroy_zone(t_zone *zone)
{
	size_t length;

	length = zone->map_length;
	unlink_zone(&g_zones[zone->type], zone);
	munmap((void *)zone, length);
}

void ft_free(void *ptr)
{
	t_zone  *zone;
	t_block *block;

	if (!ptr)
		return;

	block = payload_to_block(ptr);

	zone = block->zone;

	if (zone->type == LARGE)
	{
		destroy_zone(zone);
		return ;
	}
	block->free = 1;
	block = merge_blocks(block);
	if (block->prev == NULL)
		zone->first = block;
	if (zone_is_empty(zone))
		destroy_zone(zone);

	return ;
}