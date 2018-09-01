/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 21:48:10 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/08 20:48:22 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;
	char	a;
	size_t	i;

	a = (char)c;
	pointer = (char*)s;
	i = 0;
	while (pointer[i])
	{
		if (pointer[i] == a)
			return (pointer + i);
		i++;
	}
	if (pointer[i] == a)
		return (pointer + i);
	return (NULL);
}
