/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/30 15:59:36 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		free_str(char *str)
{
	free(str);
	return ();
}

int		get_next_line(int const fd, char ** line)
{
	char	buff[BUFF_SIZE];
	int		ret;
	
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	if ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';

	}
	return (ret);
}
