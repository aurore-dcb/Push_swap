NAME = push_swap
SRCS = sources/main.c sources/parsing.c sources/sorting_fct.c sources/ft_utils.c  sources/first_sort.c sources/create_list.c sources/sorting_move.c 
OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
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