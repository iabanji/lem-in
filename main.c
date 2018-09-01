/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:31:42 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/25 17:36:39 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		search_fd(int ac, char **av)
{
	int		fd;

	g_graf = ft_strnew(0);
	g_st = ft_strnew(0);
	g_end = ft_strnew(0);
	g_val = 0;
	g_ants = -1;
	g_rooms = -1;
	g_i = 0;
	g_j = 0;
	g_k = 0;
	if (ac < 2)
		fd = 0;
	else if (ac > 2)
		return (-1);
	else
		fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("Cannot read file or many arguments\n");
	return (fd);
}

void	add_new_room(char *str)
{
	char	*tmp;
	char	**exp;

	exp = ft_strsplit(str, ' ');
	if (exp[1] == NULL || exp[2] == NULL || exp[3] != NULL)
		ft_putstr("Don't valid room\n");
	if (exp[1] == NULL || exp[2] == NULL || exp[3] != NULL)
		exit(1);
	if (valid_rooms(exp[0]) < 1 || is_room(exp[0], 1) == 1)
		exit(1);
	if (!g_graf && ft_strequ(exp[0], g_st) == 0 &&
		ft_strequ(exp[0], g_end) == 0)
		g_graf = ft_strjoin(exp[0], " ");
	else if (ft_strequ(exp[0], g_st) == 0 && ft_strequ(exp[0], g_end) == 0)
	{
		tmp = ft_strdup(g_graf);
		free(g_graf);
		g_graf = ft_strjoin(tmp, exp[0]);
		free(tmp);
		tmp = ft_strdup(g_graf);
		free(g_graf);
		g_graf = ft_strjoin(tmp, " ");
		free(tmp);
	}
	free_split(exp);
}

void	add_new_con(char *str)
{
	char	*tmp;
	char	**exp;

	exp = ft_strsplit(str, '-');
	if (exp[2] != NULL || ft_strequ(exp[0], exp[1]) == 1)
	{
		ft_putstr("Don't valid connection\n");
		exit(1);
	}
	if (!g_buf)
		g_buf = ft_strjoin(str, " ");
	else
	{
		tmp = ft_strdup(g_buf);
		free(g_buf);
		g_buf = ft_strjoin(tmp, str);
		free(tmp);
		tmp = ft_strdup(g_buf);
		free(g_buf);
		g_buf = ft_strjoin(tmp, " ");
		free(tmp);
	}
	free_split(exp);
}

void	analys_str(char *str)
{
	if (g_i == 0)
	{
		g_ants = ((ft_isdigit(str[0]) == 1) ? ft_atoi(str) : (0));
		g_i = 1;
	}
	if (ft_strequ(str, "##start") == 1)
		g_k = 1;
	else if (g_k == 1 && g_st[0] == '\0')
	{
		parse_str(str, 0);
		g_k = 0;
	}
	if (ft_strequ(str, "##end"))
		g_j = 1;
	else if (g_j == 1 && g_end[0] == '\0')
	{
		parse_str(str, 1);
		g_j = 0;
	}
	if (is_sym_in(str, '-') > 0 && is_sym_in(str, ' ') < 1 && str[0] != '#')
		add_new_con(str);
	if (is_sym_in(str, ' ') && str[0] != '#')
		add_new_room(str);
}

int		main(int ac, char **av)
{
	char	*str;
	int		fd;

	if ((fd = search_fd(ac, av)) == -1)
		exit(1);
	while (get_next_line(fd, &str))
	{
		if (str[0] == '\0')
		{
			free(str);
			valid_lem();
			start_trafic();
		}
		analys_str(str);
		free(str);
	}
	valid_lem();
	start_trafic();
	return (0);
}
