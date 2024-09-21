/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_tests.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:54:04 by zslowian          #+#    #+#             */
/*   Updated: 2024/09/21 20:20:39 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf

void    ft_is_nl_test();
void    ft_strlcpy_test();

void    ft_strlcpy_test()
{
    char    *dst;
    size_t  size;
    size_t  result;
    
    size = BUFFER_SIZE * 42 + 1;
    dst = ft_calloc(size + 1, sizeof(char));
    printf("------------ Tests for ft_strlcpy() ------------\n\n");
    result = ft_strlcpy(dst, "\n", 3);
    if(result != 1)
        printf("\nFirst test case failed!\n");
    ft_strlcpy(dst, "123\0\0\0", 4);
    result = ft_strlcpy(dst, "abc", 3);
    if(result != 3)
        printf("\nSecond test case failed!\n");
    ft_strlcpy(dst, "\0\0\0\0\0\0\0\0", 6);
    
    printf("------------ Tests for fft_strlcpy() finished ------------\n\n");
    free(dst);
}

void    ft_is_nl_test()
{
    char    *buffer;
    size_t  size_to_check;
    int     result;

    size_to_check = 3;
    buffer = ft_calloc(size_to_check + 1, sizeof(char));
    printf("------------ Tests for ft_is_nl() ------------\n\n");
    ft_strlcpy(buffer, "e\n\n", 3);
    result = ft_is_nl(buffer, 0, size_to_check);
    if(result != 1)
        printf("\nFirst test case failed!\n");
    ft_strlcpy(buffer, "\0\0\0\0", 4);
    ft_strlcpy(buffer, "My ", 3);
    result = ft_is_nl(buffer, 0, size_to_check);
    if(result != -1)
        printf("\nSecond test case failed!\n");
    ft_strlcpy(buffer, "\0\0\0\0", 4);
    ft_strlcpy(buffer, "M", 3);
    result = ft_is_nl(buffer, 0, size_to_check);
    if(result != -1)
        printf("\nThird test case failed!\n");
    ft_strlcpy(buffer, "\0\0\0\0", 4);
    ft_strlcpy(buffer, "", 3);
    result = ft_is_nl(buffer, 0, size_to_check);
    if(result != -1)
        printf("\nFourth test case failed!\n");
    ft_strlcpy(buffer, "\0\0\0\0", 4);
    ft_strlcpy(buffer, "\n\n\n", 3);
    result = ft_is_nl(buffer, 0, size_to_check);
    if(result != 0)
        printf("\nFifth test case failed!\n");
    ft_strlcpy(buffer, "\0\0\0\0", 4);
    ft_strlcpy(buffer, "!!\n", 3);
    result = ft_is_nl(buffer, 0, size_to_check);
    if(result != 2)
        printf("\nSixth test case failed!\n");
    ft_strlcpy(buffer, "\0\0\0\0", 4);
    result = ft_is_nl(buffer, 0, size_to_check);
    if(result != -1)
        printf("\nSeventh test case failed!\n");
    printf("------------ Tests for ft_is_nl() finished ------------\n\n");
    free(buffer);
}

