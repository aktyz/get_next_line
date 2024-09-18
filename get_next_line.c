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

char			*get_next_line(int fd);
static char		*laddle_from_fd(int fd);
static int		is_new_line(int start_index, char *buffer);

char	*get_next_line(int fd)
{
	static char	*basin_buffer;

	basin_buffer = laddle_from_fd(fd);
	return (basin_buffer);
}

/**
 * This function laddle BUFFER_SIZE string from fd,
 * checking if there's a NL in it.
 * If there is a NL it returns only the portion to the NL
 * together with NL sign
 */
static char	*laddle_from_fd(int fd)
{
	int		bytes_read;
	char	*cup_buffer;
	char	*shorter_cup_buffer;
	int		nl_position;

	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(cup_buffer), NULL);
	nl_position = is_new_line(0, cup_buffer);
	if (nl_position != (-1) && nl_position < BUFFER_SIZE)
	{ //reallocate the memory - TODO: extract to utils
		shorter_cup_buffer = ft_calloc (nl_position + 1, sizeof(char));
		if (shorter_cup_buffer == NULL)
			return (NULL);
		ft_strlcpy(shorter_cup_buffer, cup_buffer, nl_position + 1);
		return (free(cup_buffer), shorter_cup_buffer);
	}
	else
		return (cup_buffer);
}

/**
 * Starting from the start_index,
 * the buffer is checked for a new line char
 * Returning the position of '\0' or
 * (-1) if no new line found
 *
 */
static int	is_new_line(int start_index, char *buffer)
{
	while (buffer[start_index] != '\0')
		start_index++;
	if (buffer[start_index] == '\0')
		return (start_index);
	else
		return (-1);
}
