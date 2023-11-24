/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:17:01 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/24 12:23:27 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*str;
	char	*str2;
	char	*str3;
	size_t	i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	i = atoi(argv[4]);
	while (--i)
	{
		str = get_next_line(fd);
		printf("%s", str);
		str2 = get_next_line(fd2);
		printf("%s", str2);
		str3 = get_next_line(fd3);
		printf("%s", str3);
		free(str);
		free(str2);
		free(str3);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}