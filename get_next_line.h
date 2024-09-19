/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:54:46 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/22 04:54:46 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <stdlib.h> // malloc free
# include <unistd.h> // read

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_is_new_line(char *buffer, int start, size_t buffer_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size, int start);
#endif
