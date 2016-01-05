/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/30 18:27:55 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		
{
	
}

int		free_str(char *str, int ret)
{
	free(str);
	return (ret);
}

int		get_next_line(int const fd, char ** line)
{
	char		buff[BUFF_SIZE];
	int			ret;
	t_data		*data;

	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	if (!(ret = )
	{
		while ((ret = read(fd, buff, BUFF_SIZE)))
		{
			buff[ret] = '\0';
		}
	}
	return (ret);
}
