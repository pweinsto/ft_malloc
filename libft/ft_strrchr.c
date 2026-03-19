/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:37:58 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:28:26 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
	{
		return ((char *) &s[i]);
	}
	while (i != 0)
	{
		if (s[i - 1] == c)
		{
			return ((char *) &s[i - 1]);
		}
		i--;
	}
	return (0);
}
