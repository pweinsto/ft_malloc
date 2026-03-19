/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:54:18 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:28:20 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
	{
		return ((char *) &haystack[0]);
	}
	while (haystack[i] != 0 && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
			{
				return ((char *) &haystack[i]);
			}
		}
		i += 1;
		j = 0;
	}
	return (0);
}
