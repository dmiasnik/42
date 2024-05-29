NAME = philo_bonus
SRC = main.c utils.c philo.c utils2.c philo_create.c
OBJS = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -fsanitize=thread
RM = rm -f

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	${RM} ${OBJS} 

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
