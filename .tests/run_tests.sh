# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 04:59:54 by zslowian          #+#    #+#              #
#    Updated: 2024/05/22 21:41:01 by zslowian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cp ../get_next_line.c ./get_next_line.c
cp ../get_next_line_utils.c ./get_next_line_utils.c
cp ../get_next_line.h ./get_next_line.h

cc -Wall -Wextra -Werror -D BUFFER_SIZE=3 *.c -o tests.out

./tests.out

rm ./tests.out
rm ./get_next_line.c
rm ./get_next_line_utils.c
rm ./get_next_line.h
