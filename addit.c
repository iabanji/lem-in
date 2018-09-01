/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:58:30 by giabanji          #+#    #+#             */
/*   Updated: 2018/03/15 17:58:33 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_sym_in(char *str, char c)
{
	int		i;
	int		tmp;

	tmp = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			tmp++;
		if (tmp > 0)
			return (1);
	}
	return (0);
}

int		min_cifer_end(void)
{
	int		i;
	char	**exp;
	int		tmp;

	exp = ft_strsplit(g_graf, ' ');
	i = -1;
	tmp = 0;
	while (++i < g_rooms - 1)
	{
		if (g_con[i][g_rooms - 1] > 0 && tmp == 0)
			tmp = g_con[i][g_rooms - 1];
		else if (g_con[i][g_rooms - 1] < tmp && g_con[i][g_rooms - 1] > 0)
			tmp = g_con[i][g_rooms - 1];
	}
	if (tmp == 0)
	{
		free_split(exp);
		ft_putstr("The start room don't have connection with the end room!\n");
		exit(0);
	}
	free_split(exp);
	return (tmp);
}

void	add_new_connect(void)
{
	int		tmp;
	int		i;
	int		j;
	char	**exp;

	tmp = 2;
	exp = ft_strsplit(g_graf, ' ');
	i = -1;
	while (++i < g_rooms)
	{
		j = -1;
		while (++j < g_rooms)
		{
			if (g_con[i][j] == tmp - 1)
				ins_con_to_tab(exp[j], tmp, j);
		}
		if (i == g_rooms - 1 && tmp < g_rooms - 1)
		{
			tmp++;
			i = -1;
		}
	}
	free_split(exp);
}

int		return_num(char *str)
{
	int		i;
	char	**exp;

	exp = ft_strsplit(g_graf, ' ');
	i = -1;
	while (exp[++i] != NULL)
	{
		if (ft_strequ(str, exp[i]) == 1)
		{
			free_split(exp);
			return (i);
		}
	}
	free_split(exp);
	return (-1);
}

void	parse_str(char *str, int i)
{
	char	**exp;

	exp = ft_strsplit(str, ' ');
	if (i == 0)
	{
		free(g_st);
		g_st = ft_strdup(exp[0]);
		if (valid_rooms(g_st) < 1 || is_room(g_st, 1) == 1)
			ft_putstr("Not valid start room\n");
		if (valid_rooms(g_st) < 1 || is_room(g_st, 1) == 1)
			exit(1);
	}
	if (i == 1)
	{
		free(g_end);
		g_end = ft_strdup(exp[0]);
		if (valid_rooms(g_end) < 1 || is_room(g_end, 1) == 1)
			ft_putstr("Not valid end room\n");
		if (valid_rooms(g_end) < 1 || is_room(g_end, 1) == 1)
			exit(1);
	}
	free_split(exp);
}
