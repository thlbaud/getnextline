/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:33:13 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/22 15:49:30 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_fill_buff(char	*buff)
{
	size_t	index;
	size_t	offset;

	index = 0;
	while (buff[index] && buff[index] != '\n')
		index++;
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

char	*ft_to_create_line(int fd, char *buff, char *line)
{
	/*line = ft_strcpy_limit(buff, ft_strchr(buff));
	if (!line)
			return (NULL);
	if (read(fd, buff, BUFFER_SIZE) <= 0)
			return (free(line), NULL);*/
	while (ft_strchr(line) == 0)
	{
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
		if (ft_strchr(line) > 0)
			return (line);
		if (read(fd, buff, BUFFER_SIZE) <= 0)
			return (free(line), NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "\0";
	char	*line;

	if (buff[0] == 0)
		if (read(fd, buff, BUFFER_SIZE) <= 0)
			return (NULL);
	if (buff[0] && (ft_strchr(buff) > 0 || buff[0] == '\n'))
	{
		line = ft_strcpy_limit(buff, ft_strchr(buff));
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

