/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:41:50 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/08 11:37:12 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pointer;
	unsigned char	a;
	size_t			i;

	a = (unsigned char)c;
	pointer = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (pointer[i] == a)
			return (pointer + i);
		i++;
	}
	return (NULL);
}
