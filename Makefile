# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 16:34:36 by aducobu           #+#    #+#              #
#    Updated: 2023/05/27 00:48:09 by aducobu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			push_swap
INCLUDE = 		-I./headers/push_swap.h -I./libft/libft.h
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
				sources/ft_free.c
				#gnl/get_next_line.c gnl/get_next_line_utils.c
BONUS_OBJS = 	${BONUS_SRCS:.c=.o}


CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc

RM = rm -f

all:		${NAME}

libft/libft.a:
			make -C libft

${NAME}:	${OBJS} libft/libft.a
			${CC} ${CFLAGS} -I./headers/push_swap.h -o ${NAME} ${OBJS} -Llibft -lft

bonus:		${OBJS} ${BONUS_OBJS}
			${CC} ${CFLAGS} ${INCLUDE} -o ${BONUS_NAME} ${BONUS_SRCS}

clean:
			make -C libft clean
			${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
			make -C libft fclean
			${RM} ${NAME} ${BONUS_NAME}
	
re:	fclean all


# NAME = push_swap
# INCLUDE = -I./headers -I./libft
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# SRCS = 			sources/main.c \
# 				sources/parsing.c \
# 				sources/sorting_fct.c \
# 				sources/ft_utils.c  \
# 				sources/first_sort.c \
# 				sources/create_list.c \
# 				sources/sorting_move.c \
# 				sources/pre_tri.c \
# 				sources/pre_tri2.c \
# 				sources/ft_free.c
# OBJS = ${SRCS:.c=.o}

# all: $(NAME)

# libft/libft.a:
# 	make -C libft

# $(NAME): $(OBJS) libft/libft.a
# 	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) -Llibft -lft

# obj/%.o: src/%.c
# 	mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

# clean:
# 	make -C libft clean
# 	rm -rf $(OBJS)
# 	rm -rf obj

# fclean: clean
# 	make -C libft fclean
# 	rm -rf $(NAME)

# re: fclean all

# val:        $(NAME)
# 	valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=readline.supp --track-origins=yes ./${NAME}

# .PHONY: all clean fclean re