/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:30:47 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:28:38 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	ptr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!ptr)
		return (0);
	if (start < ft_strlen(s))
	{
		while (i < len && s[i] != 0)
		{
			ptr[i] = s[start + i];
			i++;
		}
	}
	ptr[i] = 0;
	return (ptr);
}
