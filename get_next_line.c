/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/03/22 16:29:43 by vcaquant         ###   ########.fr       */
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
	{
		i++;
		ft_putstr("1,2,3...");
	}
	ft_putstr("len");
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	static char		buff[2] = "";
	int				i;

	ft_putstr("hey\n");
	i = 0;
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	ft_putstr("premier if\n");
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
//		ft_putstr(buff);
		ft_putstr("avant\n");
		*line = malloc(100 * sizeof(char));
		ft_putstr("apres\n");
		*line[0] = '\0';
		ft_putstr("premier while\n");
		if ((ft_strchr(buff, '\n')) != NULL || (ft_strchr(buff, '\0')) != NULL)
		{
			ft_putstr("rentre\n");
			while (buff[i] != '\n' && buff[i] != '\0')
			{
				ft_strncat(line[i], buff, 1);
				ft_putstr("\033[032;31m");
				ft_putstr(line[i]);
				ft_putstr("\033[0m");
				ft_putchar('\n');
				ft_putstr("je sais pas\n");
				i++;
				ft_putstr("avant 2eme\n");
			}
			if (buff[i] == '\n' || buff[i] == '\0')
				return (1);
		}
		ft_putstr("rentre pas\n");
//		if (ret < 0)
//			return (free_str(buff, -1));
	}
	return (0);
}
