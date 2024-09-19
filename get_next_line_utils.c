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

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size, int start);

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
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}

