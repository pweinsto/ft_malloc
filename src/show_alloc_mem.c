#include "../inc/ft_malloc.h"
#include "../libft/libft.h"
#include <stdint.h>

void ft_puthex_fd(uintptr_t ptr, int fd)
{
	char    buf[2 + sizeof(uintptr_t) * 2 + 1];
	char    *base;
	int     i;

	base = "0123456789abcdef";
	if (ptr == 0)
	{
		ft_putstr_fd("0x0", fd);
		return ;
	}

	i = sizeof(buf) - 1;
	buf[i] = '\0';
	while (ptr > 0)
	{
		buf[--i] = base[ptr % 16];
		ptr /= 16;
	}
	buf[--i] = 'x';
	buf[--i] = '0';
	ft_putstr_fd(&buf[i], fd);
}

static void *block_to_payload(t_block *block)
{
	return ((void *)((char *)block + BLOCK_OVERHEAD));
}

void print_block(t_block *block, size_t *total)
{
	uintptr_t   start;
	uintptr_t   end;

	if (block->free)
		return ;

	start = (uintptr_t)block_to_payload(block);
	end = start + block->size;
	ft_puthex_fd(start, 1);
	ft_putstr_fd(" - ", 1);
	ft_puthex_fd(end, 1);
	ft_putstr_fd(" : ", 1);
	ft_putnbr_fd(block->size, 1);
	ft_putstr_fd(" bytes\n", 1);
	*total += block->size;
}

void print_zone_list(char *name, t_zone *zone, size_t *total)
{
	t_block *block;

	while(zone)
	{
		ft_putstr_fd(name, 1);
		ft_putstr_fd(" : ", 1);
		ft_puthex_fd((uintptr_t)zone, 1);
		ft_putstr_fd("\n", 1);
		block = zone->first;
		while (block)
		{
			print_block(block, total);
			block = block->next;
		}
		zone = zone->next;
	}
}

void show_alloc_mem(void)
{
	size_t  total;

	total = 0;
	print_zone_list("TINY", g_zones[TINY], &total);
	print_zone_list("SMALL", g_zones[SMALL], &total);
	print_zone_list("LARGE", g_zones[LARGE], &total);
	ft_putstr_fd("Total : ", 1);
	ft_putnbr_fd(total, 1);
	ft_putstr_fd(" bytes\n", 1);
}