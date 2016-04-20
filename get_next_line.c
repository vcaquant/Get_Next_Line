/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/04/20 15:48:20 by vcaquant         ###   ########.fr       */
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
	//char			**data;

	i = 0;
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_putstr(buff);
		ft_putstr("avant\n");
		save = malloc(100 * sizeof(char));
		//data = malloc(100 * sizeof(char));
		//*line = malloc(100 * sizeof(char));
		ft_putstr("apres\n");
		//*line[0] = '\0';
		ft_putstr("premier while\n");
		if ((ft_strchr(buff, '\n')) != NULL)
		{
			ft_strjoin(save, buff);
			ft_putstr("rentre\n");
			while (buff[i] != '\n' && buff[i] != '\0')
			{
				line[i] = ft_strsub(buff, i, 1);
				ft_putstr("\033[032;31m");
				ft_putstr(line[i]);
				ft_putchar('\n');
				ft_putstr(*line);
				ft_putstr("\033[0m");
				ft_putchar('\n');
				i++;
				ft_putstr("avant 2eme\n");
			}
			if (buff[i] == '\n' || buff[i] == '\0')
			{
				//ft_strcpy(*line, *data);
				ft_putstr("\033[033;33m");
				ft_putstr(*line);
				ft_putchar('\n');
				ft_putstr("\033[0m");
				ret = 1;
			}
			else
				ret = 0;
		}
		ft_putstr("rentre pas\n");
//		if (ret < 0)
//			return (free_str(buff, -1));
	}
	ft_putstr("avant return\n");
	return (ret);
}
