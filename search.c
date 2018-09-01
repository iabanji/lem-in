/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:32:57 by giabanji          #+#    #+#             */
/*   Updated: 2018/03/01 14:33:11 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_ride(void)
{
	char	**exp;
	int		i;
	char	*tmp;

	exp = ft_strsplit(g_min_road, ' ');
	i = 0;
	while (++i < g_len)
	{
		if (g_traf[i] > 0)
		{
			tmp = ft_itoa(g_traf[i]);
			write(1, "L", 1);
			write(1, tmp, ft_strlen(tmp));
			write(1, "-", 1);
			write(1, exp[i], ft_strlen(exp[i]));
			write(1, " ", 1);
			free(tmp);
		}
	}
	write(1, "\n", 1);
	free_split(exp);
}

void	one_move(void)
{
	int		i;
	int		tmp1;
	int		tmp2;

	i = -1;
	while (++i < g_len)
	{
		if (i == 0)
		{
			tmp2 = ((g_traf[i] > 0) ? g_ants - g_traf[0] + 1 : 0);
			tmp1 = 0;
			if (g_traf[i] > 0)
				g_traf[0]--;
		}
		else if (i == g_len - 1 && tmp2 > 0)
			g_traf[g_len - 1]++;
		else
		{
			tmp1 = g_traf[i];
			g_traf[i] = tmp2;
			tmp2 = tmp1;
		}
	}
}

void	move_ants(void)
{
	int		i;
	char	**exp;

	i = -1;
	g_traf = (int*)malloc(sizeof(int) * g_len);
	exp = ft_strsplit(g_min_road, ' ');
	while (++i < g_len)
		g_traf[i] = 0;
	g_traf[0] = g_ants;
	while (g_traf[g_len - 1] != g_ants)
	{
		one_move();
		put_ride();
	}
	free_split(exp);
}

void	join_str(int nb)
{
	char	*tmp;
	char	**exp;
	char	*tmp1;

	exp = ft_strsplit(g_graf, ' ');
	tmp = ft_strdup(g_min_road);
	free(g_min_road);
	tmp1 = ft_strjoin(exp[nb], " ");
	g_min_road = ft_strjoin(tmp1, tmp);
	free(tmp);
	free(tmp1);
	free_split(exp);
}

void	search_min_road(void)
{
	char	**exp;
	int		i;
	int		tmp;
	int		nb;

	g_min_road = ft_strdup(g_end);
	exp = ft_strsplit(g_graf, ' ');
	tmp = min_cifer_end();
	g_len = tmp + 1;
	nb = g_rooms - 1;
	while (tmp > 0)
	{
		i = -1;
		while (++i < g_rooms)
		{
			if (g_con[i][nb] == tmp && g_con[i][nb] != 0)
			{
				nb = i;
				tmp--;
				join_str(i);
				break ;
			}
		}
	}
	free_split(exp);
}
