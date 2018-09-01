/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:17:24 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/10 18:26:05 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cat(char *str)
{
	int		fd;
	int		ret;
	char	buf[4096];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("cat: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	else
	{
		ret = read(fd, buf, 4096);
		buf[ret] = '\0';
		ft_putstr(buf);
		fd = close(fd);
		if (fd == -1)
			ft_putstr("CLOSE() error.\n");
	}
}
