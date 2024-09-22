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

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcpy(char *dest, const char *src);
void		*ft_calloc(size_t nmemb, size_t size);

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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char) c)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*ptr;

	if (!s2)
		return (0);
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	len_s1 = 0;
	len_s2 = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	while (s2[len_s2] != '\0')
		len_s2++;
	ptr = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!ptr)
		return (0);
	ft_strcpy(ptr, s1);
	ft_strcpy(ptr + len_s1, s2);
	while (*s2 != '\0')
	{
		*s2 = '\0';
		s2++;
	}
	return (free(s1), ptr);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
