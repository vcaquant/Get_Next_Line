/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:00:41 by vcaquant          #+#    #+#             */
/*   Updated: 2015/12/28 14:24:20 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "srclibft/libft.h"

# define BUFF_SIZE 32

typedef struct	s_data
{
	char			*data;
}				t_data;

int				get_next_line(int const fd, char ** line);
int				main(int argc, char **argv);

#endif
