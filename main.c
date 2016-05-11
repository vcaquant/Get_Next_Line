/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:10:02 by vcaquant          #+#    #+#             */
/*   Updated: 2016/05/11 18:18:23 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line = NULL;
	int		fd = open("./caca.txt", O_RDONLY);
	ft_putnbr(get_next_line(fd, &line));
	ft_putendl(line);								//affiche la 1ere ligne
	close(fd);
	return (0);
}
*/
#include "get_next_line.h"
//#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     main(int ac, char **av)
{
	int     fd;
	char    *line;
	int		i;
	int		j;
	int		k;

	j = ac;
	k = 1;
	if (j < 2)											//1 fichier
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() error");
			return (1);
		}
		while ((i = get_next_line((int const)fd, &line)) > 0)
		{
			ft_putchar('[');
			ft_putnbr(i);
			ft_putchar(']');
			ft_putendl(line);							//affiche tout le fichier
			free(line);
		}
		ft_putchar('[');
		ft_putnbr(i);
		ft_putchar(']');
	}
	while (j >= 2)										//multi fd
	{
		fd = open(av[k], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() error");
			return (1);
		}
		while ((i = get_next_line((int const)fd, &line)) > 0)
		{
			ft_putchar('[');
			ft_putnbr(i);
			ft_putchar(']');
			ft_putendl(line);							//affiche tout le fichier
			free(line);
		}
		ft_putchar('[');
		ft_putnbr(i);
		ft_putchar(']');
		k++;
		j--;
	}
	return (1);
}
