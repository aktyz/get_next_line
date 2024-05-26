/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 04:53:32 by zslowian          #+#    #+#             */
/*   Updated: 2024/05/22 04:53:32 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
# include <stdlib.h> // malloc free
# include <unistd.h> // read
#include <fcntl.h> // open

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY | O_CREAT);
	printf("fd = %d\n", fd);
	sleep(100);
	return (0);
}
