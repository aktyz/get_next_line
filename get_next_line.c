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
static void		ft_strappend(char *buffer, char *laddle, int start_position);
static char		*ft_change_mem_size(char *old_buffer, size_t old_size, size_t new_size);
static char		*ft_return_line(char *buffer, size_t buffer_size, int nl_position);

char			*get_next_line(int fd)
{
	static char	*buffer;
	size_t		buffer_size;
	int			nl_position;
	int			buffer_position;
	char		*laddle;

	buffer_size = BUFFER_SIZE * 42 + 1;
	nl_position = -1;
	buffer_position = 0;
	buffer = ft_calloc((int) buffer_size, sizeof(char));
	if(buffer == NULL)
		return (NULL);
	printf("\nBefore starting the while loop:\n\tbuffer is: \"%s\"\n\tbuffer_position is %d\n\tbuffer_size is: %ld\n\n\n", buffer,
		buffer_position, buffer_size);
	while (nl_position == (-1) || nl_position > buffer_position)
	{
		if (buffer_position == (int) buffer_size)
		{
			buffer = ft_change_mem_size(buffer, buffer_size, buffer_size * 2);
			buffer_size = buffer_size * 2;
		}
		laddle = laddle_from_fd(fd);
		printf("Laddle got from the file: \"%s\"\n", laddle);
		ft_strappend(buffer, laddle, buffer_position);
		nl_position = ft_is_new_line(buffer, buffer_position, buffer_position + BUFFER_SIZE);
		buffer_position = buffer_position + BUFFER_SIZE;
		printf("After appending it to the buffer:\n\tbuffer is: \"%s\"\n\tbuffer_position is %d\n\tbuffer_size is: %ld\n\n\n", buffer,
			buffer_position, buffer_size);
		printf("End of while:\n\tnl_position: %d\n\tbuffer_position: %d\n\n", nl_position, buffer_position);
	}
	printf("We are breaking the loop correctly after which the segmentation fault is happening");
	laddle = ft_return_line(buffer, buffer_size, nl_position);
	return (laddle);
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

/** Function takes the previously allocated memory,
 * copies new_size of it to the newly allocated one
 * frees the memory of the larger pointer and returns
 * pointer to the new bit of memory
 *
 * TODO: change name to more appropriate
 */
static char	*ft_change_mem_size(char *old_buffer, size_t old_size, size_t new_size)
{
	char	*new_buffer;

	new_buffer = ft_calloc((int) new_size, sizeof(char));
	if (new_buffer == NULL)
		return (NULL);
	ft_strlcpy(new_buffer, old_buffer, (int) old_size, 0);
	return (free(old_buffer), new_buffer);
}

/**
 * Function adding laddle content in the end of the buffer,
 * starting from start_position.
 */
static void	ft_strappend(char *buffer, char *laddle, int start_position)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[start_position] = laddle[i];
		i++;
		start_position++;
	}
}

static char	*ft_return_line(char *buffer, size_t buffer_size, int nl_position)
{
	char	*to_be_returned;
	char	*rest;
	int		new_nl_position;

	printf("\n\n\nDo we enter here?\n\n\n");
	to_be_returned = ft_calloc(nl_position, sizeof(char));
	ft_strlcpy(to_be_returned, buffer, nl_position, 0); // MOVE THE LINE TO A DIFFERENT MEMORY PART
	new_nl_position = ft_is_new_line(buffer, nl_position + 1, BUFFER_SIZE); // CALCULATE THE END OF REST IN THE BIG BUFFER
	rest = ft_calloc(new_nl_position - nl_position + 1, sizeof(char));
	ft_strlcpy(rest, buffer, new_nl_position - nl_position, nl_position + 1); // MOVE THE REST TO THE BEGINING OF THE BUFFER (STATIC)
	buffer = ft_change_mem_size(buffer, buffer_size, BUFFER_SIZE * 42 + 1); // CHANGE THE SIZE OF THE BUFFER TO THE SIZE FROM THE get_next_line() beggining
	ft_strlcpy(buffer, rest, new_nl_position - nl_position, 0);
	return(to_be_returned);
}
