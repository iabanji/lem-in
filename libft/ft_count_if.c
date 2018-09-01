/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:01:16 by giabanji          #+#    #+#             */
/*   Updated: 2017/11/10 18:01:47 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			counter++;
		i++;
	}
	return (counter);
}
