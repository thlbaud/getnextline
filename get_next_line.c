/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:02 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/19 16:48:27 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
# include <unistd.h>

#include <fcntl.h>
#include <stdio.h>

char	*_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	index;
	size_t	index2;

	dest = malloc(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1);
	if (!dest)
		return (NULL);
	index = 0;
	while (s1 && s1[index])
	{
		dest[index] = s1[index];
		index++;
	}
	index2 = 0;
	while (s2 && s2[index2])
	{
		dest[index] = s2[index2];
		index2++;
		index++;
	}
	dest[index] = 0;
	return (dest);
}

char *_create_line(int fd, char *buff)
{
	char	*line;
	char	*temp_cpy;
	char	*temp_line;
	int		size;
	
	temp_line = NULL;
	line = NULL;
	while (_strchr(line, '\n') == 0)
	{
		size = ft_strlen(buff, '\n');
		temp_cpy = _strncpy(buff, size);
		if (!temp_line)
			return (NULL);
		_fill_buff(buff, &buff[size], size);
		line = _strjoin(temp_line, temp_cpy);
		if (!line)
			return (NULL);
		free (temp_line);
		temp_line = line;
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0)
			return (_reset_buff(buff), NULL);
		buff[size] = 0;
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
		if (size < 0)
			return (_reset_buff(buff), NULL);
		buff[size] = 0;
	}
	size = _strchr(buff, '\n');
	if (size > 0)
	{
		line = _strncpy(buff, size);
		if (!line)
			return (_reset_buff(buff), NULL);
		_fill_buff(buff, &buff[size], size);
		return (line);
	}
	line = _create_line(fd, buff);
	if (!line)
		return (NULL);
	_fill_buff(buff, &buff[size], size);
	return (line);
}

int	main(void)
{
	char	*test;
	int 	fd;

	fd = open("test.txt", W_OK);
	for (int i = 0; i < 1; i++)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free (test);
	}
	return (1);
}