/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pweinsto <pweinsto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:21:53 by pweinsto          #+#    #+#             */
/*   Updated: 2021/06/25 15:59:49 by pweinsto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	ptr = 0;
	while (lst != 0)
	{
		new = ft_lstnew(f(lst -> content));
		if (new == 0)
			ft_lstclear(&new, del);
		else
			ft_lstadd_back(&ptr, new);
		lst = lst -> next;
	}
	return (ptr);
}
