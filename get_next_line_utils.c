/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:42:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/19 16:46:11 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	_fill_buff(char *buff, char *save, int target)
{
	int	index;
	int	index_save;

	index = 0;
	index_save = 0;
	while (buff[index] && index < target)
	{
		buff[index] = save[index_save];
		save[index_save] = 0;
		++index;
	}
}

void	_reset_buff(char *buff)
{
	int	index;

	index = 0;
	while (index < BUFFER_SIZE)
	{
		buff[index] = 0;
		++index;
	}
}

int	ft_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	_strchr(char *str, char target)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == target)
			return (index);
		++index;
	}
	return (0);
}

char *_strncpy(char *src, int size)
{
	char	*cpy;
	int		index;
	
	if (!src)
		return (NULL);
	cpy = calloc(sizeof(char), (size + 1));
	if (!cpy)
		return (NULL);
	index = 0;
	while (src[index] && index < size)
	{
		cpy[index] = src[index];
		src[index] = 0;
		++index;
	}
	return (cpy);
}