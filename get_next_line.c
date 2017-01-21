/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:44:31 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/21 14:04:17 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	store_rest(char *str, char **rest)
{
	if (*str)
		*rest = ft_strdup(str);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*end_line;
	char			buf[BUF_SIZE + 1];
	static	char	*rest = "";

	// Protections contre parametres invalides
	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	// Il reste des chars du read precedent a afficher
	if (*rest)
	{
		if ((end_line = ft_strchr(rest, '\n')))
		{
			*end_line = '\0';
			*line = ft_strjoinf(*line, rest, 1);
			store_rest(++end_line, &rest);
			if (ft_strequ(rest, *line))
				*rest = '\0';
			return (1);
		}
		else
			*line = ft_strjoinf(*line, rest, 1);
		if (!ft_strchr(rest, '\n'))
			*rest = '\0';
	}
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((end_line = ft_strchr(buf, '\n')))
		{
			*end_line = '\0';
			store_rest(++end_line, &rest);
			*line = ft_strjoinf(*line, buf, 1);
			return (1);
		}
		*line = ft_strjoinf(*line, buf, 1);
	}
	// On est arrive a la fin du fichier
	if (**line && ret == 0)
		return (1);
	return (ret);
}
