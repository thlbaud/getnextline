/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:33:13 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/19 22:13:29 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	ft_strchr(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n' || s[i] == 0)
			return (1);
	if (s[i] == '\n' || s[i] == 0)
		return (1);
	return (0);
}


t_list	*ft_lstnew(int fd)
{
	t_list	*lst;
	char	*str;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	str = calloc(1, BUFFER_SIZE);
	if (!str)
	{
		free (lst);
		return (NULL);
	}
	lst->content = ft_fill_buf(str, fd);
	lst->next = NULL;
	return (lst);
}

char	*ft_return_line(t_list *lst, size_t len)
{
	char	*line;
	size_t	index_line;
	size_t	index_lst;

	line = calloc(1, len + 1);
	if (!line)
		return (NULL);
	index_lst = 0;
	index_line = 0;
	while (lst->content[index_lst] != '\n')
	{
		while (lst->content[index_lst] != 0 && lst->content[index_lst] != '\n')
			lst->content[index_lst++] = line[index_line++];
		if (lst->content[index_lst] != '\n')
			return (line);
		lst = lst->next;
		index_lst = 0;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	t_list	*lst;
	t_list	*temp;
	t_list	*new;
	size_t	index;
	size_t	len_global;

	lst = ft_lstnew(fd);
	temp->next = lst;
	index = 0;
	while (lst->content[index])
		index++;
	if (lst->content[index - 1] == '\n')
		return (lst->content);
	index = 0;
	while (ft_strchr(lst->content) == 0)
	{
		new = ft_lstnew(fd);
		lst->next = new;
		index++;
	}
	len_global = index * BUFFER_SIZE + ft_strlen(lst->content);
	lst = temp->next;
	return (ft_return_line(lst, len_global));
}

