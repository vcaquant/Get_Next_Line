/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:10:02 by vcaquant          #+#    #+#             */
/*   Updated: 2016/04/22 16:33:17 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line = NULL;
	int		fd = open("./caca.txt", O_RDONLY);
	ft_putnbr(get_next_line(fd, &line));
	close(fd);
	return (0);
}
