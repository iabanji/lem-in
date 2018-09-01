/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giabanji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:27:31 by giabanji          #+#    #+#             */
/*   Updated: 2017/12/07 16:02:12 by giabanji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_validbuf(char **line, t_lst **list, int n)
{
	size_t	i;
	char	*s;
	t_lst	*p;

	p = *list;
	i = 0;
	while (p != NULL && p->index != n)
		p = p->next;
	if (p == NULL)
		return (0);
	if (p->bufer == NULL)
		return (0);
	while (p->bufer[i] != '\n' && p->bufer[i])
		i++;
	*line = ft_strsub(p->bufer, 0, i);
	if (i + 1 >= ft_strlen(p->bufer))
		ft_memdel((void **)&p->bufer);
	else
	{
		s = ft_strdup(p->bufer);
		ft_memdel((void **)&p->bufer);
		p->bufer = ft_strsub(s, i + 1, ft_strlen(s) - i + 1);
		free(s);
	}
	return (1);
}

void	ft_readtmp(t_lst **list, char *tmp, int n)
{
	char	*s;
	t_lst	*p;

	p = *list;
	while (p != NULL && p->index != n)
		p = p->next;
	if (!(p))
	{
		p = (t_lst *)malloc(sizeof(t_lst));
		p->index = n;
		p->bufer = NULL;
		p->next = *list;
		*list = p;
	}
	if ((p->bufer))
	{
		s = ft_strdup(p->bufer);
		ft_memdel((void **)&(p->bufer));
		p->bufer = ft_strjoin(s, tmp);
		free(s);
	}
	else if (!(p->bufer))
		p->bufer = ft_strdup(tmp);
}

int		get_next_line(const int fd, char **line)
{
	char			*tmp;
	int				ret;
	static t_lst	*p;

	if (fd < 0 || !line || BUFF_SIZE < 1 || (read(fd, 0, 0)))
		return (-1);
	tmp = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		ft_readtmp(&p, tmp, fd);
		if (ft_strchr(tmp, '\n'))
			break ;
		ft_memset(tmp, 0, BUFF_SIZE);
	}
	free(tmp);
	if (ret == -1)
		return (-1);
	ret = ft_validbuf(line, &p, fd);
	return (ret);
}
