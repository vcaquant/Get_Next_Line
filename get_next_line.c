/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/05/04 16:57:57 by vcaquant         ###   ########.fr       */
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

int		get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	char			*save;
	int				ret;

	save = ft_strnew(1);
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_putstr("BUFF\n");
		ft_putstr(buff);
		ft_putchar('\n');
		save = ft_strjoin(save, buff);
		ft_putstr("SAVE\n");
		ft_putstr("\033[032;31m");
		ft_putstr(save);
		ft_putstr("\033[0m");
		ft_putchar('\n');
	}
	*line = ft_strsub(save, 0, ft_strnlen(save, '\n'));
	ft_putstr("LINE\n");
	ft_putstr("\033[033;33m");
	ft_putstr(*line);
	ft_putchar('\n');
	ft_putstr("\033[0m");
	ret = 1;
	//if 
	//	ret = 0;
	if (ret < 0)
		return (free_str(buff, -1));
	return (ret);
}
