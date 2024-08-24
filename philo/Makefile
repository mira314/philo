SRCS = utlis.c main.c check.c init.c \
		thread_utils.c routing.c action.c

OBJS = ${SRCS:.c=.o}

NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread -g

all: ${NAME}

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $?

$(NAME)	: $(OBJS)
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME)

clean :
	-rm -f ${OBJS}

fclean: clean
	-rm -f ${NAME}

re : fclean all

