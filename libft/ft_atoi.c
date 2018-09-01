/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:40:37 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/11 12:29:02 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					i;
	long long int		nbr;
	int					negative;

	nbr = 0;
	negative = 1;
	i = 0;
	while (ft_istab(str[i]))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
		nbr = nbr * 10 + (long long int)str[i++] - '0';
	return ((int)nbr * negative);
}
