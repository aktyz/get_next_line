/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:53:32 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/22 04:53:32 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
#include <fcntl.h> // open

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("../.examples/short.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file!\n");
		return (1);
	}
	while(1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		printf("\n\n--------------(%d)NL returned: \"%s\"",
			count, next_line);
		count++;
		free(next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
