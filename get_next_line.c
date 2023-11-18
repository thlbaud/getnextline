/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:04:05 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/18 21:16:40 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_set_line(char *str, size_t index)
{
	char	*line;

	line = calloc(1, index + 2);
	if (!line)
	{
		free (str);
		return (NULL);
	}
	index = 0;
	while (str[index])
	{
		line[index] = str[index];
		index++;
	}
	free (str);
	return (line);

}

char	*get_next_line(int fd)
{
	char	*tempo;
	size_t	index;

	tempo = calloc(1, BUFFER_SIZE);
	if (!tempo)
		return (NULL);
	index = 0;
	read(fd, &tempo[index], 1);
	while (index < BUFFER_SIZE && tempo[index] != '\n' && tempo[index] != 0)
	{
		index++;
		read(fd, &tempo[index], 1);
	}
	if (index == BUFFER_SIZE && tempo[index] != '\n')
		return (ft_set_line(tempo, index));
	return (tempo);
}

int	main(int argc, char **argv)
{
	int		fd;
	size_t	i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	i = 32;
	while (--i)
		printf("%s", get_next_line(fd));
	close(fd);
	write(1, "\n", 1);
	return (0);
}
