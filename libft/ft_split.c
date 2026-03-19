/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:57:11 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 16:56:30 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_all_delimiter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (0);
}

static char	**ft_create_malloc(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**ptr;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			count += 1;
			while (s[i] != c && s[i] != 0)
				i++;
		}
	}
	ptr = (char **)malloc((sizeof(char *) * (count + 1)));
	return (ptr);
}

static char	**ft_split_loop(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	end;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			end = i;
			ptr[j] = ft_substr(s, start, end - start);
			start = end;
			j++;
		}
	}
	ptr[j] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s || ft_all_delimiter(s, c) == 1)
		return (0);
	ptr = ft_create_malloc(s, c);
	if (!ptr)
		return (0);
	return (ft_split_loop(ptr, s, c));
}
