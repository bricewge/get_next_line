/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:44:31 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/18 13:30:40 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		byte_read;
	char	buf[BUF_SIZE + 1];

	byte_read = 0;
	if (fd > 0)
		return (-1);
	else
	{
		*line = ft_strnew(0);
		while ((byte_read = read(fd, buf, BUF_SIZE)) > 0)
		{
			buf[byte_read] = '\0';
			*line = ft_strjoin(*line, buf);
		}
		if (byte_read == -1)
			return (-1);
	}
	if (byte_read == -1)
		return (-1);
	return (1);
}
