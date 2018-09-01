/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:44:50 by giabanji          #+#    #+#             */
/*   Updated: 2018/02/28 13:22:34 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*g_buf;
char	*g_st;
char	*g_end;
int		g_ants;
int		g_rooms;
int		**g_con;
int		*g_traf;
char	*g_min_road;
char	*g_tmp;
int		g_min_len;
char	*g_graf;
int		g_len;

int		g_i;
int		g_j;
int		g_k;
int		g_val;

void	start_trafic(void);
void	search_min_road(void);
void	move_ants(void);
void	valid_lem(void);
void	count_uniq_room(char **exp);
void	parse_str(char *str, int i);
int		return_num(char *str);
void	ins_con_to_tab(char *str, int nb, int j);
void	add_new_connect(void);
int		min_cifer_end(void);
int		valid_rooms(char *str);
int		valid_connection(void);
void	free_split(char **arr);
int		is_sym_in(char *str, char c);
int		is_room(char *str, int dc);

#endif
