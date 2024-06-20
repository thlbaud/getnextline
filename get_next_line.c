/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:02 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/20 13:59:25 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*_create_line(int fd, char *buff)
{
	char	*line;
	char	*temp;
	int		size;

	line = NULL;
	temp = NULL;
	size = BUFFER_SIZE;
	while (!ft_strrchr(line, '\n') && size == BUFFER_SIZE)
	{
		temp = ft_strjoin(line, buff);
		_fill_buff(buff);
		if (line)
			free (line);
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0)
			return (free (temp), NULL);
		line = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			size;

	if (!buff[0])
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size <= 0)
			return (_reset_buff(buff), NULL);
		buff[size] = 0;
	}
	size = ft_strlen(buff, '\n');
	if (size < BUFFER_SIZE)
	{
		line = _strncpy(buff, size + 1);
		if (!line)
			return (_reset_buff(buff), NULL);
		_fill_buff(buff);
		return (line);
	}
	line = _create_line(fd, buff);
	if (!line)
		return (NULL);
	return (line);
}

int	main(void)
{
	char	*test;
	int 	fd;

	fd = open("test.txt", W_OK);
	for (int i = 0; i < 5; i++)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free (test);
	}
	return (1);
}