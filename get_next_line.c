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
static int		ft_is_new_line(char *buffer, int start, t_size buffer_size);
static int		ft_charcmp(char char1, char char2);
static void		ft_strappend(char *buffer, char *laddle, int start_position);
static char		*ft_change_mem_size(char *old_buffer, size_t old_size, size_t new_size);
char			*ft_return_line(char *buffer, t_size buffer_size, int nl_position);

char			*get_next_line(int fd)
{
	static char	*buffer;
	t_size		buffer_size;
	int			nl_position;
	int			buffer_position;

	buffer_size = BUFFER_SIZE * 42 + 1;
	nl_position = -1;
	buffer_position = 0;
	buffer = ft_calloc((int) buffer_size, sizeof(char));
	if(buffer_size == NULL)
		return (NULL);
	while (nl_position != -1)
	{
		if (buffer_position == buffer_size)
		{
			buffer = ft_change_mem_size(buffer, buffer_size, buffer_size * 2);
			buffer_size = buffer_size * 2;
		}
		ft_strappend(buffer, laddle_from_fd(fd), buffer_position);
		nl_position = ft_is_new_line(buffer, buffer_position, BUFFER_SIZE);
		buffer_position = buffer_position + BUFFER_SIZE;
	}
	//Move part of the return string after the NL sign to the static variable - and return new line
	return (ft_return_line(buffer, buffer_size, nl_position));
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
}*/

/**
 * Function scans the buffer searching for NL char position.
 *
 * Returning the position of NL or
 * (-1) if no new line found.
 */
static int	ft_is_new_line(char *buffer, int start, t_size buffer_size)
{
	while (start < buffer_size + 1 && ft_charcmp(buffer[start],'\0'))
		start++;
	printf("Position of the NL char is %d, content under it: %c\n", start, buffer[start]);
	if (start != buffer_size && ft_charcmp(buffer[start],'\0'))
		return (start);
	else
		return (-1);
}
/**
 * Function compares two characters and returns 0 if
 * they are the same or the difference between them.
 */
static int		ft_charcmp(char char1, char char2)
{
	if (char1 - char2 != 0)
		return (char1 - char2);
	return (0);
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

char	*ft_return_line(char *buffer, t_size buffer_size, int nl_position)
{
	char	*to_be_returned;
	int		new_nl_position;

	to_be_returned = ft_calloc(nl_position, sizeof(char));
	ft_strlcpy(to_be_returned, buffer, nl_position, 0); // MOVE THE LINE TO A DIFFERENT MEMORY PART
	new_nl_position = ft_is_new_line(buffer, nl_position + 1, BUFFER_SIZE); // CALCULATE THE END OF REST IN THE BIG BUFFER
	ft_strlcpy(buffer, buffer, new_nl_position - nl_position); // MOVE THE REST TO THE BEGINING OF THE BUFFER (STATIC)
	buffer = ft_change_mem_size(buffer, buffer_size, BUFFER_SIZE * 42 + 1); // CHANGE THE SIZE OF THE BUFFER TO THE SIZE FROM THE get_next_line() beggining
	return(free(to_be_returned), to_be_returned);
}
