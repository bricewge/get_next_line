/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:44:31 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/23 14:07:24 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	store_rest(char *str, char **rest)
{
	char *tmp;

	if (*str)
	{
		tmp = *rest;
		*rest = ft_strdup(str);
		free(tmp);
	}
}

int		use_rest(char **line, char **rest, char **end_line)
{
	if (*rest && **rest)
	{
		if ((*end_line = ft_strchr(*rest, '\n')))
		{
			**end_line = '\0';
			*line = ft_strjoinf(*line, *rest, 1);
			store_rest(++(*end_line), rest);
			if (ft_strequ(*rest, *line))
				ft_strclr(*rest);
			return (1);
		}
		else
			*line = ft_strjoinf(*line, *rest, 1);
		if (!ft_strchr(*rest, '\n'))
			ft_strclr(*rest);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*end_line;
	char			buf[BUFF_SIZE + 1];
	static	char	*rest[OPEN_MAX];

	if (fd < 0 || !line || (fd > OPEN_MAX))
		return (-1);
	*line = ft_strnew(0);
	if (use_rest(line, &rest[fd], &end_line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((end_line = ft_strchr(buf, '\n')))
		{
			*end_line = '\0';
			store_rest(++end_line, &rest[fd]);
			*line = ft_strjoinf(*line, buf, 1);
			return (1);
		}
		*line = ft_strjoinf(*line, buf, 1);
	}
	if (**line && ret == 0)
		return (1);
	return (ret);
}
