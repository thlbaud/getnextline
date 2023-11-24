/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line _bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:06:42 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/23 22:18:59 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_reset_buff(char	*buff);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strchr(const char *s, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcpy_limit(char *buff, size_t len);

#endif