/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:27:35 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/10 18:09:55 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_tab(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	len = (int)ft_strlen(s) - 1;
	j = 0;
	while ((is_tab(s[i])) && s[i] != '\0')
		i++;
	while ((is_tab(s[len])) && len >= 0)
		len--;
	if (len < i)
		return (ft_strnew(0));
	if (!(str = (char*)malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	while (i <= len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
