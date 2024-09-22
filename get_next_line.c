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

char		*get_next_line(int fd);
static char	*read_to_buffer(char *buffer, int fd);
static char	*get_line_from_buffer(char *buffer);
static char	*update_buffer(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = read_to_buffer(buffer, fd);
	if (!buffer)
		return (0);
	line = get_line_from_buffer(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

static char	*read_to_buffer(char *buffer, int fd)
{
	char	*tmp;
	int		bytes;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	if (!tmp)
		return (0);
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			if (buffer)
				free(buffer);
			free(tmp);
			return (0);
		}
		if (bytes)
			buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

static char	*get_line_from_buffer(char *buffer)
{
	char	*line;
	size_t	nl_pos;

	nl_pos = 0;
	if (!buffer[nl_pos])
		return (0);
	while (buffer[nl_pos] && buffer[nl_pos] != '\n')
		nl_pos++;
	if (buffer[nl_pos] == '\n')
		nl_pos++;
	line = ft_calloc(nl_pos + 1, sizeof(char));
	if (!line)
		return (0);
	while (--nl_pos + 1)
		line[nl_pos] = buffer[nl_pos];
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (0);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	i++;
	str = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!str)
		return (0);
	while (buffer[i])
		str[j++] = buffer[i++];
	free(buffer);
	return (str);
}
