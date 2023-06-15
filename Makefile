# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 16:34:36 by aducobu           #+#    #+#              #
#    Updated: 2023/05/31 10:43:29 by aducobu          ###   ########.fr        #
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
				sources/sort_len3.c \
				sources/little_cases.c \
				sources/sort_len5.c \
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
				sources/sort_len3.c \
				sources/little_cases.c \
				sources/sort_len5.c \
				sources/ft_free.c

BONUS_OBJS = 	${BONUS_SRCS:.c=.o}

CFLAGS		=	-Wall -Wextra -Werror -g3
CC			=	gcc

RM			=	rm -f

all:		${NAME}

libft/libft.a:
			make -C libft

${NAME}:	${OBJS} libft/libft.a
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -Llibft -lft

bonus:		${BONUS_OBJS} libft/libft.a
			${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} -Llibft -lft

clean:
			make -C libft clean
			${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
			make -C libft fclean
			${RM} ${NAME} ${BONUS_NAME}
	
re:	fclean all
