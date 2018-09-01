/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:25:22 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/08 18:41:46 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	a;
	size_t			i;

	if (dst == src)
		return (dst);
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == a)
		{
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
