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
static int		ft_strappend(char *buffer, char *laddle, int start_position, int n);

char			*get_next_line(int fd)
{
	static t_buffer	*buffer;
	char			*to_be_returned;

	buffer = ft_initialize_buffer(buffer, BUFFER_SIZE);
	if(fd < 0 || buffer->buffer == NULL)
		return (NULL);
	else if (buffer->laddle == NULL)
		return (NULL);
	
	if(buffer->laddle_nl != -1)
	{
		//here I should return again a NL in the end and update the buffer content
	}

	while (buffer->laddle_nl == -1)
	{
		if (buffer->buffer_position == (int) buffer->buffer_size - 1)
			buffer = ft_change_size_buffer(buffer, buffer->buffer_size * 2);
		buffer->laddle = laddle_from_fd(fd);
		if(!(buffer->laddle == NULL) && buffer->laddle_nl == -1)
		{
			buffer->laddle_nl = ft_is_nl(buffer->laddle, 0, BUFFER_SIZE);
			if (buffer->laddle_nl == -1)
				buffer->buffer_position = ft_strappend(buffer->buffer, buffer->laddle, buffer->buffer_position, BUFFER_SIZE);
			else
			{
				buffer->buffer_position = ft_strappend(buffer->buffer, buffer->laddle, buffer->buffer_position, BUFFER_SIZE);
				buffer->buffer_nl = ft_is_nl(buffer->buffer, 0, buffer->buffer_position + buffer->laddle_nl);
				to_be_returned = ft_calloc(buffer->buffer_position, sizeof(char));
				ft_strlcpy(to_be_returned, buffer->buffer, buffer->buffer_nl, 0);
				buffer = ft_move_rest_to_buffer(buffer);
			}
		}
		else
			break;
	}
	return (to_be_returned);
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
	char	*laddle;

	laddle = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (laddle == NULL)
		return (NULL);
	bytes_read = read(fd, laddle, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(laddle), NULL);
	return (laddle);
}

/**
 * Function adding laddle content in the end of the buffer,
 * starting from buffer_start_position, appending n chars
 */
static int	ft_strappend(char *buffer, char *laddle, int buffer_start_position, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		buffer[buffer_start_position] = laddle[i];
		i++;
		buffer_start_position++;
	}
	return buffer_start_position;
}
