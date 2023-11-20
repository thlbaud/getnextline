/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:26:43 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/19 21:22:58 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_buf(char *str, int fd)
{
	size_t index;
	char	*temp;

	index = 0;
	read(fd, &str[index], 1);
	while (index < BUFFER_SIZE && str[index] != '\n' && str[index] != 0)
	{
		index++;
		read(fd, &str[index], 1);
	}
	if (str[index] == '\n')
	{
		temp = calloc(1, index + 2);
		index = -1;
		while (str[++index])
			temp[index] = str[index];
		return (temp);	
	}
	return (str);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = ft_lstsize(lst) - 1;
	while (i > 0)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
