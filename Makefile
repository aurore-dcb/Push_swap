NAME = push_swap
SRCS = main.c parsing.c sorting_fct.c ft_utils.c the_sort.c first_sort.c
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