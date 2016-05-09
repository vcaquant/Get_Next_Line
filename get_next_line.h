/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:00:41 by vcaquant          #+#    #+#             */
/*   Updated: 2016/05/09 18:41:27 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE 100

typedef struct	s_g
{
	char		buff[BUFF_SIZE + 1];
	char		*save;
	int			pass;
	int			ret;
}				t_g;

int				get_next_line(int const fd, char **line);

#endif
