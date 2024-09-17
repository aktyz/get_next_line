/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:51:31 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/22 04:51:31 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf

char		*get_next_line(int fd);
static char	*read_from_file(int fd);

char	*get_next_line(int fd)
{
	char	*basin_buffer;

	basin_buffer = read_from_file(fd);
	return (basin_buffer);
}

static char	*read_from_file(int fd)
{
	int			bytes_read;
	char		*cup_buffer;
	static int	count;

	count = 1;
	printf("ft_calloc#[%d]---", count++);
	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(cup_buffer), NULL);
	return (cup_buffer);
}
