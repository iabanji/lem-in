/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:39:56 by giabanji          #+#    #+#             */
/*   Updated: 2018/03/04 19:40:02 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_split(char **arr)
{
	int		i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i] != NULL)
		free((char*)arr[i]);
	free((char*)arr);
}

int		is_room(char *str, int dc)
{
	int		i;
	char	**exp;

	if (g_graf[0] == '\0' && dc == 0)
		exit(1);
	if (g_graf[0] == '\0' && dc == 1)
		return (0);
	exp = ft_strsplit(g_graf, ' ');
	i = -1;
	while (exp[++i] != NULL)
	{
		if (ft_strequ(exp[i], str) == 1)
		{
			if (dc == 1)
				ft_putstr("Not valid rooms\n");
			free_split(exp);
			return (1);
		}
	}
	free_split(exp);
	return (0);
}

int		valid_connection(void)
{
	int		i;
	char	**exp1;
	char	**exp2;

	if (g_graf[0] == '\0' || !g_buf)
	{
		ft_putstr("Bad conection\n");
		return (0);
	}
	exp1 = ft_strsplit(g_buf, ' ');
	i = -1;
	while (exp1[++i] != NULL)
	{
		exp2 = ft_strsplit(exp1[i], '-');
		if (is_room(exp2[0], 0) < 1 || is_room(exp2[1], 0) < 1)
		{
			ft_putstr("Bad connection\n");
			free_split(exp1);
			free_split(exp2);
			return (0);
		}
		free_split(exp2);
	}
	free_split(exp1);
	return (1);
}

int		valid_rooms(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'L' || str[i] == '-')
		{
			ft_putstr("Don't valid room\n");
			return (0);
		}
	}
	return (1);
}

void	valid_lem(void)
{
	if (g_ants < 1)
		ft_putstr("Ants < 1\n");
	if (g_st[0] == '\0' || g_end[0] == '\0')
		ft_putstr("Map don't have start or end\n");
	if (g_ants < 1 || g_st[0] == '\0' || g_end[0] == '\0')
		exit(1);
}
