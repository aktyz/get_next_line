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

char			*try_get_next_line(int fd);
static char		*laddle_from_fd(int fd);
static int		is_new_line(char *buffer);
static char		*new_string(char *old_string, size_t new_string_length);
static int		ft_charcmp(char char1, char char2);

char	*try_get_next_line(int fd)
{
	static char	*basin_buffer;

	basin_buffer = laddle_from_fd(fd);
	printf("\"%s\"\n", basin_buffer);
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
	int		nl_position;

	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(cup_buffer), NULL);
	nl_position = is_new_line(cup_buffer);
	if (nl_position != (-1) && nl_position < BUFFER_SIZE)
		cup_buffer = new_string(cup_buffer, nl_position + 1);
	return (cup_buffer);
}

/** Function takes the previously allocated memory,
 * copies n size of it to the newly allocated one
 * frees the memory of the larger pointer and returns
 * pointer to the new bit of memory
 *
 */
static char	*new_string(char *old_string, size_t new_string_length)
{
	char	*new_string;

	new_string = ft_calloc((int) new_string_length, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, old_string, (int) new_string_length);
	return (free(old_string), new_string);
}

/**
 * Starting from the start_index,
 * the buffer is checked for a new line char
 * Returning the position of '\0' or
 * (-1) if no new line found
 *
 */
static int	is_new_line(char *buffer)
{
	int start;

	start = 0;
	while (start < BUFFER_SIZE + 1 && ft_charcmp(buffer[start],'\0'))
		start++;
	printf("Position of the NL char is %d, content under it: %c\n", start, buffer[start]);
	if (start != BUFFER_SIZE && ft_charcmp(buffer[start],'\0'))
		return (start);
	else
		return (-1);
}

static int		ft_charcmp(char char1, char char2)
{
	if (char1 - char2 != 0)
		return (char1 - char2);
	return (0);
}
