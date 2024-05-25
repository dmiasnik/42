NAME = libftprintf.a

SRCFILES = ft_printf.c hex.c hexp.c nbr.c put.c unbr.c

OPTION = -c -I 
FLAGS = -Wall -Wextra -Werror
OBJFILES = ${SRCFILES:.c=.o}


all:	$(NAME)

%.o: %.c
	cc ${FLAGS} -c $< -o $@

$(NAME):	${OBJFILES}
	ar -rc $(NAME) $(OBJFILES)

bonus:	${OBJFILES}
	ar -rc $(NAME) $(OBJFILES)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:     all clean fclean re
