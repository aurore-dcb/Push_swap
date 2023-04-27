NAME = push_swap
SRCS = sources/main.c sources/parsing.c sources/sorting_fct.c sources/ft_utils.c sources/the_sort.c sources/first_sort.c
OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = gcc

RM = rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}
	
re:	fclean all