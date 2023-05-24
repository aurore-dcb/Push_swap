# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 16:34:36 by aducobu           #+#    #+#              #
#    Updated: 2023/05/22 14:42:25 by aducobu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = sources/main.c \
		sources/parsing.c \
		sources/sorting_fct.c \
		sources/ft_utils.c  \
		sources/first_sort.c \
		sources/create_list.c \
		sources/sorting_move.c \
		sources/sort_3.c \
		sources/sort_5.c \
		sources/ft_free.c
OBJS = ${SRCS:.c=.o}

BONUS_NAME = checker
BONUS_SRCS = bonus/main_bonus.c \
			 bonus/sorting_bonus.c \
			 bonus/sorting_fct_bonus.c \
			 sources/parsing.c \
			 sources/sorting_fct.c \
			 sources/ft_utils.c  sources/first_sort.c sources/create_list.c sources/sorting_move.c sources/sort_3.c sources/sort_5.c sources/ft_free.c Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c 
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

RM = rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}

bonus:		${OBJS} ${BONUS_OBJS}
			${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_SRCS}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
			${RM} ${NAME} ${BONUS_NAME}
	
re:	fclean all