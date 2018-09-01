/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trafic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:44:06 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/28 15:44:30 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_start_end(void)
{
	char	*tmp1;
	char	*tmp2;

	if (g_graf[0] == '\0' && (g_st[0] == '\0' || g_end[0] == '\0'))
	{
		if (g_st[0] == '\0' && g_end[0] == '\0')
			ft_putstr("Map don't have rooms\n");
		else if (g_st[0] == '\0' && g_end[0] != '\0')
			ft_putstr("Map have only end room\n");
		else if (g_st[0] != '\0' && g_end[0] == '\0')
			ft_putstr("Map have only start room\n");
		if (!g_buf)
			ft_putstr("Map don't have links\n");
		exit(1);
	}
	tmp1 = ft_strdup(g_graf);
	free(g_graf);
	tmp2 = ft_strjoin(g_st, " ");
	g_graf = ft_strjoin(tmp2, tmp1);
	free(tmp1);
	free(tmp2);
	tmp1 = ft_strdup(g_graf);
	free(g_graf);
	g_graf = ft_strjoin(tmp1, g_end);
	free(tmp1);
}

void	ins_con_to_tab(char *str, int nb, int j)
{
	char	**exp1;
	char	**exp2;
	char	*tmp;
	int		i;

	exp1 = ft_strsplit(g_buf, ' ');
	i = -1;
	while (exp1[++i] != NULL)
	{
		exp2 = ft_strsplit(exp1[i], '-');
		if (ft_strequ(str, exp2[0]) == 1 || ft_strequ(str, exp2[1]) == 1)
		{
			if (ft_strequ(str, exp2[0]) == 1)
				tmp = ft_strdup(exp2[1]);
			else
				tmp = ft_strdup(exp2[0]);
			if (return_num(tmp) >= 0 && (g_con[j][return_num(tmp)] > nb
				|| g_con[j][return_num(tmp)] == 0))
				g_con[j][return_num(tmp)] = nb;
			free(tmp);
		}
		free_split(exp2);
	}
	free_split(exp1);
}

void	do_table(void)
{
	int		i;
	int		j;

	g_con = (int**)malloc(sizeof(int*) * g_rooms);
	i = 0;
	while (i < g_rooms)
	{
		g_con[i] = (int*)malloc(sizeof(int) * g_rooms);
		i++;
	}
	i = -1;
	while (++i < g_rooms)
	{
		j = -1;
		while (++j < g_rooms)
			g_con[i][j] = 0;
	}
}

void	count_rooms(void)
{
	char	**exp;
	int		i;

	exp = ft_strsplit(g_graf, ' ');
	i = -1;
	while (exp[++i] != NULL)
		g_rooms++;
	g_rooms++;
	free_split(exp);
}

void	start_trafic(void)
{
	add_start_end();
	count_rooms();
	if (valid_connection() < 1)
		exit(1);
	if (g_rooms < 2)
	{
		ft_putstr("Rooms < 2\n");
		return ;
	}
	do_table();
	ins_con_to_tab(g_st, 1, 0);
	add_new_connect();
	search_min_road();
	move_ants();
	exit(1);
}
