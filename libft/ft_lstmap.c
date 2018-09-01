/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:00:43 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/10 17:08:30 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*header;

	new_list = NULL;
	if (lst == NULL)
		return (NULL);
	header = f(lst);
	new_list = header;
	while (lst->next)
	{
		new_list->next = f(lst->next);
		lst = lst->next;
		new_list = new_list->next;
	}
	return (header);
}
