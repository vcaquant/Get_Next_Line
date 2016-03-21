/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/03/21 16:44:16 by vcaquant         ###   ########.fr       */
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
	static char		buff[BUFF_SIZE + 1];
	int				i;

	ft_putstr("hey\n");
	i = 0;
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	ft_putstr("premier if\n");
	while (read(fd, buff, 1))
	{
		buff[BUFF_SIZE] = '\0';
		ft_putstr("avant");
		*line = malloc((ft_strnlen(buff, '\n')) * sizeof(char));
		ft_putstr("apres");
		*line[0] = '\0';
		ft_putstr("premier while\n");
		if (ft_strchr(buff, '\n') != NULL)
		{
			while (buff[i] != '\n' || buff[i] != '\0')
			{
				ft_strncat(*line, buff, 1);
				ft_putstr(*line);
				ft_putstr("je sais pas");
			}
			if (buff[i] == '\n' || buff[i] == '\0')
				return (1);
			i++;
		}
//		if (ret < 0)
//			return (free_str(buff, -1));
	}
	return (0);
}
