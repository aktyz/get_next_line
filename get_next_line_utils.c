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
size_t	ft_strlcpy(char *dst, const char *src, size_t size, int start);
int		ft_is_new_line(char *buffer, int start, size_t size_to_check);

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
 * (Copied from Libft)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size, int start)
{
	size_t	i;

	i = 0;
	if (i < size)
	{
		while (i < size - 1)
		{
			dst[i] = src[start];
			i++;
			start++;
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
int	ft_is_new_line(char *buffer, int start, size_t size_to_check)
{
	while (start < (int) size_to_check + 1 && buffer[start] - 13 != 0)
	{
		printf("\nLookinf for the NL:\n\tstart is %d\n\tsize_to check is %ld\n\tbuffer[start] is '%c'\n\n",
			start, size_to_check, buffer[start]);
		start++;
	}
	printf("\nPosition of the NL char is %d,\n\tcontent under it: '%c'\n", start, buffer[start]);
	if (start <= (int) size_to_check && buffer[start + 1] - 13 != 0)
		return (start);
	else
		return (-1);
}
