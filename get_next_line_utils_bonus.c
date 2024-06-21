/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:42:26 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/22 00:33:27 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s, char c)
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
