/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:44:06 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 15:58:15 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr; 

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
}
