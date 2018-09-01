/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:36:14 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/09 15:06:05 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	if (str)
	{
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
