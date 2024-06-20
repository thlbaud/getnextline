/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:31:23 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/20 13:57:26 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	_fill_buff(char *buff);
char	*ft_strrchr(const char *s, int c);
void	_reset_buff(char *buff);
int		ft_strlen(const char *s, char c);
char	*_strncpy(char *src, int size);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif