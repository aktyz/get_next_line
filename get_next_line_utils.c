/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 05:30:55 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/22 05:30:55 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf

void	*ft_calloc(size_t nmemb, size_t size);
t_buffer	*ft_initialize_buffer(t_buffer *buffer, int buffer_size);
size_t	ft_strlcpy(char *dst, char *src, size_t size, int src_start);
int		ft_is_nl(char *buffer, int start, size_t size_to_check);

/**
 * Function allocates a necessary memory part, intended to
 * store nmemb number of size bits variables.
 *
 * This memory will be zeroed.
 *
 * (Copied from Libft)
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	t_size;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > 2147483647 / size)
		return (0);
	t_size = nmemb * size;
	ptr = (void *) malloc (t_size);
	if (!ptr)
		return (0);
	while (t_size--)
		((char *)ptr)[t_size] = 0;
	return (ptr);
}

/**
 * Function copy the size of content from src to the dst memory.
 *
 * Function assums that the dst is at least of size.
 *
 * It returns number of copied chars.
 *
 */
size_t	ft_strlcpy(char *dst, char *src, size_t size, int src_start)
{
	size_t	i;
	i = 0;
	if (size)
	{
		while (i < size && src[src_start] != '\0')
		{
			dst[i] = src[src_start];
			src_start++;
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}

/**
 * Function scans the buffer searching for NL char position.
 *
 * Returning the position of NL or
 * (-1) if no new line found.
 */
int	ft_is_nl(char *buffer, int start, size_t size_to_check)
{
	if (buffer[start])
	{
		while (start < (int) size_to_check + 1 && buffer[start] != '\n')
			start++;
		if (start <= (int) size_to_check /**&& buffer[start + 1] != '\n'*/)
			return (start);
		else
			return (-1);
	}
	else
		return (-1);
}

t_buffer	*ft_initialize_buffer(t_buffer *buffer, int buffer_size)
{
	buffer->buffer_size = buffer_size * 42 + 1;
	buffer->buffer = ft_calloc(buffer->buffer_size, sizeof(char));
	buffer->laddle = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer->buffer_nl = -1;
	buffer->laddle_nl = -1;
	buffer->buffer_position = 0;
	return buffer;
}

t_buffer	*ft_change_size_buffer(t_buffer *old, int new_buffer_size)
{
	static t_buffer *new;
	new->buffer_size = new_buffer_size;
	new->buffer = ft_calloc(new->buffer_size, sizeof(char));
	new->laddle = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	new->buffer_nl = old->buffer_nl;
	new->laddle_nl = old->laddle_nl;
	new->buffer_position = old->buffer_position;
	ft_strlcpy(new->buffer, old->buffer, new->buffer_position, 0);
	free(old->buffer);
	free(old->laddle);
	return (free(old), new);
}

t_buffer	*ft_move_rest_to_buffer(t_buffer *buffer)
{
	static t_buffer *new;

	new->buffer_size = BUFFER_SIZE * 42 + 1;
	new->buffer = ft_calloc(buffer->buffer_size, sizeof(char));
	new->laddle = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	ft_strlcpy(new->laddle, buffer->laddle, BUFFER_SIZE - buffer->laddle_nl, buffer->laddle_nl + 1);
	new->buffer_nl = -1;
	new->laddle_nl = ft_is_nl(new->laddle, 0, BUFFER_SIZE);
	new->buffer_position = 0;
	free(buffer->buffer);
	free(buffer->laddle);
	return (free(buffer), new);
}


