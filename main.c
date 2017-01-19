/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:24:59 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/19 18:25:12 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		result;

	if (argc > 0)
	{
		line = NULL;
		if (argc == 1)
			fd = 0;
		else
			fd = open(argv[1], O_RDONLY);
		while ((result = get_next_line(fd, &line)) > 0)
		{
			ft_putchar('(');
			ft_putnbr(result);
			ft_putchar(')');
			ft_putstr(line);
		}
		close (fd);
	}
	else
		return (1);
	return (0);
}
