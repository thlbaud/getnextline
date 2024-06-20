/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:42:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/20 13:40:05 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

void	_fill_buff(char *buff)
{
	int	index;
	int	offset;

	if (buff[0] == 0)
		return ;
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
}

void	_reset_buff(char *buff)
{
	int	index;

	index = 0;
	if (!buff[0])
		return ;
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

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	while (i != 0)
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i--;
	}
	if (s[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*_strncpy(char *src, int size)
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
		++index;
	}
	return (cpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
