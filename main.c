/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:24:59 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/18 13:35:38 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;

	if (argc > 1)
	{
		line = NULL;
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, line) > 0)
			;
		printf("%s", *line);
		close (fd);
	}
	else
		return (1);
	return (0);
}
