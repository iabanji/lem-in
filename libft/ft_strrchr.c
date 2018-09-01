/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:00:21 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/10 19:55:18 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;
	char	a;
	int		i;

	a = (char)c;
	pointer = (char*)s;
	i = 0;
	while (pointer[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (pointer[i] == a)
			return (pointer + i);
		i--;
	}
	return (NULL);
}
