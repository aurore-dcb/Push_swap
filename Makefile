# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 16:34:36 by aducobu           #+#    #+#              #
#    Updated: 2023/05/26 18:49:44 by aducobu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			push_swap
SRCS = 			sources/main.c \
				sources/parsing.c \
				sources/sorting_fct.c \
				sources/ft_utils.c  \
				sources/first_sort.c \
				sources/create_list.c \
				sources/sorting_move.c \
				sources/pre_tri.c \
				sources/pre_tri2.c \
				sources/ft_free.c
OBJS = 			${SRCS:.c=.o}

BONUS_NAME = 	checker
BONUS_SRCS = 	bonus/main_bonus.c \
				bonus/sorting_bonus.c \
				bonus/sorting_fct_bonus.c \
				bonus/sorting_fct2_bonus.c \
				sources/parsing.c \
				sources/sorting_fct.c \
				sources/ft_utils.c \
				sources/first_sort.c \
				sources/create_list.c \
				sources/sorting_move.c \
				sources/pre_tri.c \
				sources/pre_tri2.c \
				sources/ft_free.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c
BONUS_OBJS = 	${BONUS_SRCS:.c=.o}

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