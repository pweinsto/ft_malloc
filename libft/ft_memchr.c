/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:49:14 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:26:34 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char *ptr;

	i = 0;
	ptr = (unsigned char *)s;
	c = (unsigned char)c;
	while (((unsigned char *)ptr)[i] != 0 && i < n)
	{
		if (((unsigned char *)ptr)[i] == c)
		{
			return ((unsigned char *) &ptr[i]);
		}
		i++;
	}
	if (c == 0)
	{
		return ((unsigned char *) &ptr[i]);
	}
	else
	{
		return (0);
	}
}
