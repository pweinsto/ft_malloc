#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>

# define TINY_MAX		128
# define SMALL_MAX		1024
# define ALIGNMENT		16
# define ALLOCATIONS	100

typedef enum	e_zone_type
{
	TINY = 0,
	SMALL = 1,
	LARGE = 2
}	t_zone_type;

typedef struct	s_block
{
	struct s_block	*prev;
	struct s_block	*next;
	size_t			size;
	size_t			free;
}	t_block;

typedef struct	s_zone
{
	struct s_zone   *prev;
	struct s_zone	*next;
	t_zone_type		type;
	size_t			total_size;
	size_t			free_size;
	t_block			*first;
}	t_zone;


# define ALIGN_UP(x)	((((x) + (ALIGNMENT) - 1) / (ALIGNMENT)) * (ALIGNMENT))
# define BLOCK_OVERHEAD	ALIGN_UP(sizeof(t_block))
# define ZONE_OVERHEAD	ALIGN_UP(sizeof(t_zone))

extern t_zone	*g_zones[3];

void *ft_malloc(size_t size);

# endif