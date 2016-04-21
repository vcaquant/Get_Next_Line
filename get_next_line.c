/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/04/21 20:06:56 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_str(char *str, int ret)
{
	free(str);
	return (ret);
}

int		ft_strnlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

//t_data	g_data(int const fd)
//{
//	t_data		*data;
//}

int		get_next_line(int const fd, char **line)
{
	static char		buff[2] = "";
	static char		*save;
	int				i;
	int				ret;

	save = malloc(1);
	save[0] = '\0';
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		buff[ret] = '\0';
		ft_putstr(buff);
		ft_putchar('\n');
		ft_strcat(save, buff);
		ft_putstr("\033[032;31m");
		ft_putstr(save);
		ft_putstr("\033[0m");
		ft_putchar('\n');
		i = ft_strlen(save);
	}
	if ((ft_strchr(save, '\n')) != NULL)
	{
		*line = malloc(ft_strnlen(save, '\n') + 1);
		**line = '\0';
		ft_strncpy(*line, save, ft_strnlen(save, '\n'));
		ft_putstr("\033[033;33m");
		ft_putstr(*line);
		ft_putchar('\n');
		ft_putstr("\033[0m");
		ret = 1;
	}
	else
		ret = 0;
	if (ret < 0)
		return (free_str(buff, -1));
	return (ret);
}
