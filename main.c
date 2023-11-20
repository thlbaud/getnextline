/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:45:24 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/19 21:47:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	size_t	i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	i = 10;
	while (--i)
		printf("%s", get_next_line(fd));
	close(fd);
	write(1, "\n", 1);
	return (0);
}