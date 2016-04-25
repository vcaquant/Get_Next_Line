/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:10:02 by vcaquant          #+#    #+#             */
/*   Updated: 2016/04/25 14:30:00 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

//int		main(void)
//{
//	char	*line = NULL;
//	int		fd = open("./caca.txt", O_RDONLY);
//	ft_putnbr(get_next_line(fd, &line));
//	close(fd);
//	return (0);
//}

#include "get_next_line.h"
//#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     main()
{
	int     fd;
	char    *line;
	int		i;

	fd = open("caca.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while ((i = get_next_line((int const)fd, &line)) > 0)
	{
		ft_putendl("LINE");
		ft_putendl(line);
		free (line);
	}
	return (1);
}
