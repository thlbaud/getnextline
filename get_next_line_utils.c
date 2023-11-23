/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:26:43 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/23 13:41:52 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		alloc = malloc(size * nmemb);
		return (alloc);
	}
	if (size > (SIZE_MAX / nmemb) || nmemb > (SIZE_MAX / size))
		return (NULL);
	alloc = malloc(size * nmemb);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
		alloc[i++] = 0;
	return (alloc);
}

size_t	ft_strchr(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	if (size < BUFFER_SIZE)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	index;
	size_t	index2;

	dest = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	index = 0;
	if (s1)
	{
		while (s1[index] && s1[index] != '\n')
		{
			dest[index] = s1[index];
			index++;
		}
		free (s1);
	}
	index2 = 0;
	while (s2[index2] && s2[index2] != '\n')
	{
		dest[index] = s2[index2];
		index2++;
		index++;
	}
	if (s2[index2] == '\n')
		dest[index] = '\n';
	return (dest);
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
