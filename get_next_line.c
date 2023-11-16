/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:04:05 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/16 14:40:56 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h>

char	*get_next_line(int fd)
{
	int	temp_fd;
	char	*line;
	char	c;
	size_t	size;

	temp_fd = fd;
	size = 1;
	while (read(fd, &c, 1) != '\n')
		size++;
	if (read(fd, &c, 1) != 0)
		return (1);
	line = malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL)
	
	

}

int	main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	get_next_line(fd);
	close(fd);
	write(1, "\n", 1);
	return (0);
}
