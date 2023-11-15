# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 14:51:30 by dmiasnik          #+#    #+#              #
#    Updated: 2023/11/15 14:42:41 by dmiasnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror
OPT = -Lminilibx -lmlx -framework OpenGL -framework AppKit
SRC = source/so_long.c source/map.c source/move.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	gcc $(FLAGS) -c -I ./source/ $< -o $@

$(NAME):	$(OBJ)
	@make -C ./libft
	@make -C ./minilibx
	gcc $(FLAGS) libft/libft.a $(OPT) $(OBJ) -o $(NAME)

bonus:
	@make -C ./libft
	gcc $(FLAGS) libft/libft.a $(OBJ) -o $(NAME)

clean:	
	@make clean -C ./libft
#	@make clean -C ./minilibx
	rm -f $(OBJ) 

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:     all bonus clean fclean re
