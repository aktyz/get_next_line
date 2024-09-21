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
static void		ft_strappend(char *buffer, char *laddle, int start_position, int n);
static char		*ft_change_mem_size(char *old_buffer, size_t old_size, size_t new_size);

char			*get_next_line(int fd)
{
	static char	*buffer;
	size_t		buffer_size;
	int			nl_position;
	int			buffer_position;
	char		*laddle;
	char		*to_be_returned;
	char		*rest;
	int			new_nl_position;
	int			laddle_nl_position;

	buffer_size = BUFFER_SIZE * 42 + 1;
	buffer_position = 0;
	buffer = ft_calloc((int) buffer_size, sizeof(char));
	nl_position = -1;
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
		if(!(laddle == NULL))
		{

			laddle_nl_position = ft_is_nl(laddle, 0, BUFFER_SIZE); //here we check for nl already
			if (laddle_nl_position == -1)
			{
				ft_strappend(buffer, laddle, buffer_position, BUFFER_SIZE);
			}
			buffer_position = buffer_position + BUFFER_SIZE;
		}
		else
			break;
	}
	to_be_returned = ft_calloc(nl_position, sizeof(char));
	ft_strlcpy(to_be_returned, buffer, nl_position + 1); // MOVE THE LINE TO A DIFFERENT MEMORY PART
	printf("Looking for the NL in the BUFFER_SIZE after line returned:\n\tbuffer:\"%s\"\n\tnl_position: %d\n\tBUFFER_SIZE: %d\n\n", buffer, nl_position, BUFFER_SIZE);
	new_nl_position = ft_is_nl(buffer, nl_position, BUFFER_SIZE); // CALCULATE THE END OF REST IN THE BIG BUFFER
	if(new_nl_position != (-1))
	{
		rest = ft_calloc(new_nl_position - nl_position + 1, sizeof(char));
		printf("The first strlcpy went fine, arguments for the next one:\n\tnew_nl_position: %d\n\tnl_position: %d\n\trest buffor: %s\n\tbuffer: %s\n\tsize: %d\n\tstart index: %d\n\n", new_nl_position, nl_position, rest, buffer, nl_position - new_nl_position, nl_position - 1);
		ft_strlcpy(rest, buffer, nl_position - new_nl_position); // MOVE THE REST TO THE BEGINING OF THE BUFFER (STATIC)
		buffer = ft_change_mem_size(buffer, buffer_size, BUFFER_SIZE * 42 + 1); // CHANGE THE SIZE OF THE BUFFER TO THE SIZE FROM THE get_next_line() beggining
		ft_strlcpy(buffer, rest, new_nl_position - nl_position);
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
	ft_strlcpy(new_buffer, old_buffer, (int) old_size);
	return (free(old_buffer), new_buffer);
}

/**
 * Function adding laddle content in the end of the buffer,
 * starting from buffer_start_position, appending n chars
 */
static void	ft_strappend(char *buffer, char *laddle, int buffer_start_position, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		buffer[buffer_start_position] = laddle[i];
		i++;
		buffer_start_position++;
	}
}
