# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurore <aurore@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 16:34:36 by aducobu           #+#    #+#              #
#    Updated: 2023/05/19 11:10:06 by aurore           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = sources/main.c sources/parsing.c sources/sorting_fct.c sources/ft_utils.c  sources/first_sort.c sources/create_list.c sources/sorting_move.c sources/sort_3.c sources/sort_5.c
OBJS = ${SRCS:.c=.o}

BONUS_NAME = checker
BONUS_SRCS = sources/main_bonus.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

RM = rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}

bonus:		${BONUS_OBJS}
			${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_SRCS}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}
	
re:	fclean all