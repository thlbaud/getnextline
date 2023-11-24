/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:33:13 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/24 13:45:34 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_fill_buff(char	*buff)
{
	size_t	index;
	size_t	offset;

	if (buff[0] == 0)
		return (NULL);
	index = 0;
	while (buff[index] && buff[index] != '\n')
		index++;
	if (buff[index] == '\n')
		index++;
	offset = 0;
	while (buff[index])
	{
		buff[offset] = buff[index];
		offset++;
		index++;
	}
	while (buff[offset])
		buff[offset++] = 0;
	return (buff);
}

char	*ft_strcpy_limit(char *buff, size_t len)
{
	char	*dest;
	size_t	index;

	dest = ft_calloc(sizeof(char), len + 1);
	if (!dest)
		return (NULL);
	index = 0;
	while (buff && buff[index] != '\n' && buff[index])
	{
		dest[index] = buff[index];
		index++;
	}
	if (buff[index] == '\n')
		dest[index] = '\n';
	return (dest);
}

char	*ft_to_create_line(int fd, char *buff, char *line)
{
	ssize_t	size;
	int		temp;

	temp = 0;
	size = BUFFER_SIZE;
	while (ft_strchr(line, size) == 0 || temp <= 1)
	{
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_strchr(line, size) > 0)
			return (line);
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0)
			return (ft_reset_buff(buff), free(line), NULL);
		buff[size] = 0;
		if (size == 0)
			return (line);
		if (ft_strchr(buff, size) > 0 || temp > 0)
			temp++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "\0";
	char		*line;

	if (buff[0] == 0)
	{
		if (read(fd, buff, BUFFER_SIZE) < 0)
			return (ft_reset_buff(buff), NULL);
		if (buff[0] == 0)
			return (ft_reset_buff(buff), NULL);
		buff[BUFFER_SIZE] = 0;
	}
	if (buff[0] && (ft_strchr(buff, BUFFER_SIZE) > 0 || buff[0] == '\n'))
	{
		line = ft_strcpy_limit(buff, ft_strchr(buff, BUFFER_SIZE));
		if (!line)
			return (NULL);
		ft_fill_buff(buff);
		return (line);
	}
	line = NULL;
	line = ft_to_create_line(fd, buff, line);
	if (!line)
		return (NULL);
	ft_fill_buff(buff);
	return (line);
}
