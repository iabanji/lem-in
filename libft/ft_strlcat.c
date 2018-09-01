/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 21:12:02 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/08 20:28:13 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (n == 0)
		return (s2_len);
	while (s2[i] && (s1_len + i) < (n - 1))
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[s1_len + i] = '\0';
	if (s1_len < n)
		return (s1_len + s2_len);
	return (s2_len + n);
}
