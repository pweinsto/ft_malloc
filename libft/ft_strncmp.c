/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:08:42 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:28:13 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || (s1[i] == 0 || s2[i] == 0))
		{
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		}
		else
		{
			i++;
		}
	}
	return (0);
}
