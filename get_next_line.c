/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/05/09 18:53:49 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strnlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_free_first(char *str, int n)
{
	char	*new;

	new = ft_strdup(str + n + 1);
	free(str);
	return (new);
}

int		ft_init(t_g **g)
{
	if (*g == NULL)
	{
		if (!(*g = (t_g*)malloc(sizeof(t_g))))
			return (0);
		(*g)->ret = 0;
		if (!((*g)->save = ft_strnew(BUFF_SIZE + 1)))
			return (0);
	}
	else if ((*g)->save == NULL)
	{
		if (!((*g)->save = ft_strnew(BUFF_SIZE + 1)))
			return (0);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_g		*g = NULL;
	char			*tmp;

	if (!ft_init(&g))
		return (-1);
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	while (!ft_strchr(g->save, '\n'))
	{
		ft_bzero(g->buff, BUFF_SIZE + 1);
		if ((g->ret = read(fd, g->buff, BUFF_SIZE)) > 0)
		{

			tmp = ft_strjoin(g->save, g->buff);
			free(g->save);
			g->save = tmp;
		}
		else
			break ;
	}
	if (g->ret < 0)
		return (-1);
	if (g->ret == 0 && g->save[0] == '\0')
	{
		*line = NULL;
		ft_strdel(&(g->save));
		ft_memdel((void**)&g);
		return (0);
	}
	if (ft_strchr(g->save, '\n'))
	{
		*line = ft_strsub(g->save, 0, ft_strnlen(g->save, '\n'));
		g->save = ft_free_first(g->save, ft_strnlen(g->save, '\n'));
	}
	else
		*line = ft_strsub(g->save, 0, ft_strnlen(g->save, '\0'));
	return (1);
}
