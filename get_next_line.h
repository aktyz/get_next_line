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

typedef struct s_buffer
{
    char    *buffer;
    char    *laddle;
    int     buffer_size;
    int     buffer_position;
    int     buffer_nl;
    int     laddle_nl;
} t_buffer;

typedef unsigned char	t_byte;

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_is_nl(char *buffer, int start, size_t buffer_size);
size_t	ft_strlcpy(char *dst, char *src, size_t size, int src_start);
t_buffer	*ft_change_size_buffer(t_buffer *old, int new_buffer_size);
t_buffer	*ft_move_rest_to_buffer(t_buffer *buffer);
t_buffer	*ft_initialize_buffer(t_buffer *buffer, int buffer_size);

void    ft_is_nl_test();
void    ft_strlcpy_test();
#endif
