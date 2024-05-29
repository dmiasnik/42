# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 15:12:42 by dmiasnik          #+#    #+#              #
#    Updated: 2024/02/22 16:26:54 by dmiasnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCFILES = source/push_swap.c source/create.c source/count_steps.c \
			source/sort.c source/sort2.c source/sort3.c \
			source/rotate.c source/rev_rotate.c source/swap.c 
FLAGS = -Wall -Wextra -Werror
OBJFILES = ${SRCFILES:.c=.o}

all:	$(NAME)

%.o: %.c
	cc ${FLAGS} -c -I ./source/ $< -o $@

$(NAME):	$(OBJFILES)
	@make -C ./libft
	cc $(FLAGS) libft/libft.a $(OBJFILES) -o $(NAME)
	
bonus:	$(NAME)

clean:	
	@make clean -C ./libft
	rm -f $(OBJFILES)

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:     all bonus clean fclean re
