/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:31:23 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/19 16:46:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

void	_fill_buff(char *buff, char *save, int target);
int		_strchr(char *str, char target);
void	_reset_buff(char *buff);
int		ft_strlen(const char *s, char c);
char 	*_strncpy(char *src, int size);

#endif