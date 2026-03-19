/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:45:02 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:27:56 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	j;

	i = 0;
	if (!src)
		return (0);
	srclen = ft_strlen(src);
	j = srclen;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (i < dstsize - 1 && j != 0)
	{
		dst[i] = src[i];
		i++;
		j--;
	}
	dst[i] = 0;
	return (srclen);
}
