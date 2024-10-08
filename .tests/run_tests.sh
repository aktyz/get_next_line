# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 04:59:54 by zslowian          #+#    #+#              #
#    Updated: 2024/09/18 12:26:00 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cp ../get_next_line.c ./get_next_line.c
cp ../get_next_line_utils.c ./get_next_line_utils.c
cp ../get_next_line.h ./get_next_line.h

cc -Wall -Wextra -Werror -D BUFFER_SIZE=3 *.c -g -o tests.out

valgrind --leak-check=full ./tests.out

rm ./tests.out
rm ./get_next_line.c
rm ./get_next_line_utils.c
rm ./get_next_line.h
