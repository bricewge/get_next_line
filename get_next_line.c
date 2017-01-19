/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:44:31 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/19 19:19:31 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	store_rest(char *str, char **rest)
{
	int				len;

	len = ft_strlen(str);
	/* if (*rest) */
	/* 	free(*rest); */
	if (*str)
		*rest = ft_strdup(str);
}


int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*end_line;
	char			buf[BUF_SIZE + 1];
	static	char	*rest = "";

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (*rest)
	{
		if ((end_line = ft_strchr(rest, '\n')))
		{
			*end_line = '\0';
			*line = ft_strjoin(*line, rest);
			store_rest(++end_line, &rest);
			if (!ft_strchr(rest, '\n'))
				rest = "";
			return (1);
		}
		else
			*line = ft_strjoin(*line, rest);
		if (!ft_strchr(rest, '\n'))
			rest = "";
	}
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((end_line = ft_strchr(buf, '\n')))
		{
			*end_line = '\0';
			store_rest(++end_line, &rest);
			*line = ft_strjoin(*line, buf);
			return (1);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (ret);
}
