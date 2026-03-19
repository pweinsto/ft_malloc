/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:56:24 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 17:26:09 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(int n)
{
	int	i;

	i = 1;
	if (n >= 0)
	{
		while (n / 10 >= 1)
		{
			n /= 10;
			i++;
		}
	}
	else
	{
		while (n / 10 <= -1)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}

static char	*ft_positive(int n)
{
	int		i;
	char	*ptr;

	i = ft_lennbr(n);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = 0;
	while (i > 0)
	{
		ptr[i - 1] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (ptr);
}

static char	*ft_negative(int n)
{
	int		i;
	char	*ptr;

	i = ft_lennbr(n);
	ptr = (char *)malloc(sizeof(char) * (i + 2));
	if (!ptr)
		return (0);
	ptr[i + 1] = 0;
	ptr[0] = 45;
	while (i > 0)
	{
		ptr[i] = ((n % 10) * -1) + 48;
		n /= 10;
		i--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	if (n >= 0)
		return (ft_positive(n));
	else
		return (ft_negative(n));
}
