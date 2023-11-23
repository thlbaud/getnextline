/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:45:24 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/22 16:18:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	size_t	i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	i = atoi(argv[2]);
	while (--i)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	write(1, "\n", 1);
	return (0);
}
