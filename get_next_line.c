/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:16:00 by vcaquant          #+#    #+#             */
/*   Updated: 2016/05/09 16:59:59 by vcaquant         ###   ########.fr       */
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
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char	del_f(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = (ft_strnlen(str, '\n')) + 1;
	while (str[i] != '\n' && str[j] != '\n')
	{
		str[i] = str[j];
		i++;
		j++;
	}
	while (str[i] != '\n')
	{
		str[i] = 0;
		i++;
	}
	return (*str);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strnew(n + 1);
	while (i <= n && str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_free_first(char *str, int n)
{
	int		i;
	char	*new;

	i = (n - ft_strlen(str));
	new = ft_strndup(str, n);
	free(str);
	return (new);
}

int		get_next_line(int const fd, char **line)
{
	static t_g		g;

	if (g.save && ft_strchr(g.save, '\n'))
		ft_putstr("======");
	else
		g.save = ft_strnew(BUFF_SIZE + 1);
	ft_bzero(g.buff, BUFF_SIZE + 1);
	if (!line || (BUFF_SIZE <= 0))
		return (-1);
	while ((g.ret = read(fd, g.buff, BUFF_SIZE)) > 0)
	{
		g.save = ft_strjoin(g.save, g.buff);
		if (ft_strchr(g.save, '\n'))
			break ;
	}
	if (g.ret <= 0)
		return (0);
	*line = ft_strsub(g.save, 0, ft_strnlen(g.save, '\n'));
	g.save = ft_free_first(g.save, ft_strnlen(g.save, '\n'));
	///ft_putstr(g.save);
	return (1);
}
