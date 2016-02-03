/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/26 16:05:59 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_data	g_data(t_list **lst_p)
{
	t_list	*lst;
	t_data	data;

	lst = *lst_p;
	while (lst)
	{
		
	}
	return (data);
}

int		read_d(t_data *data, char **line)
{
	int		ret;
	char	*str;

	ret = 0;
	if ((str = ft_strchr(data->data, '\n')))
	{
		*str = '\0';
		str++;
		ret = 1;
	}
	*line = ft_strdup(data->data);
	if (!(*line))
		return (-1);
	if (ret)
		ft_strcpy(data->data, str);
	else
		ft_strclr(data->data);
	return (ret);
}

int		free_str(char *str, int ret)
{
	free(str);
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE];
	int			ret;
	t_data		*data;

	ret = 0;
	data = NULL;
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	if (!(ret = read_d(data, line)))
	{
		while ((ret = read(fd, buff, BUFF_SIZE)))
		{
			buff[ret] = '\0';
		}
	}
	return (ret);
}
