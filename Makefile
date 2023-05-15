# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 16:34:36 by aducobu           #+#    #+#              #
#    Updated: 2023/05/15 13:23:49 by aducobu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = sources/main.c sources/parsing.c sources/sorting_fct.c sources/ft_utils.c  sources/first_sort.c sources/create_list.c sources/sorting_move.c sources/sort_3.c
OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

RM = rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I./headers -o ${NAME} ${SRCS}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}
	
re:	fclean all