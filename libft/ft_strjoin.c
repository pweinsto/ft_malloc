/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:55:27 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:27:43 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	ptr = (char *)malloc(sizeof(char const *) * (lens1 + lens2 + 1));
	if (!ptr)
		return (0);
	while (i < lens1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		ptr[i] = s2[i - lens1];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
