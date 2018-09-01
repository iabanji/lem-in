/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:43:42 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/11 14:14:00 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_countalpha(const char *str, int len, char c)
{
	int		i;
	int		j;
	int		*count;

	if (!(count = (int*)malloc(sizeof(int) * (len + 1))))
		return (NULL);
	count[len] = 0;
	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			j++;
		else
		{
			count[i] = 0;
			while (str[j] != c && str[j] != '\0')
			{
				count[i]++;
				j++;
			}
			i++;
		}
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		*arr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	arr = ft_countalpha(s, ft_countwords(s, c), c);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (s[j] == c && s[j] != '\0')
		j++;
	while (++i < ft_countwords(s, c))
	{
		str[i] = ft_strsub(s, j, (size_t)arr[i]);
		while (s[j] != c && s[j] != '\0')
			j++;
		while (s[j] == c && s[j] != '\0')
			j++;
	}
	str[i] = 0;
	free(arr);
	return (str);
}
