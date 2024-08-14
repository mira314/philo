SRCS = utlis.c main.c check.c init.c time_utilis.c thread_utils.c routing.c print.c

OBJS = ${SRCS:.c=.o}

NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread

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

test :
	./philo 5 800 200 200 4
