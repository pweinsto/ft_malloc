/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:37:51 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/24 15:59:48 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		x = (unsigned int)(n * -1);
	}
	else
		x = (unsigned int)n;
	if (x >= 10)
		ft_putnbr_fd(x / 10, fd);
	ft_putchar_fd((x % 10) + 48, fd);
}
