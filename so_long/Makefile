# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmiasnik <dmiasnik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 14:02:32 by dmiasnik          #+#    #+#              #
#    Updated: 2024/01/06 15:20:32 by dmiasnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror 
OPT = -Lminilibx -lmlx -framework OpenGL -framework AppKit
SRC = source/so_long.c source/map.c source/move.c source/image.c 
OBJ = $(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	gcc $(FLAGS) -c -I ./source/ $< -o $@

$(NAME):	$(OBJ)
	@make -C ./libft
	@make -C ./minilibx
	gcc $(FLAGS) libft/libft.a $(OPT) $(OBJ) -o $(NAME)
	
bonus:	$(NAME)

clean:	
	@make clean -C ./libft
	@make clean -C ./minilibx
	rm -f $(OBJ) 

fclean: clean
	@make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:     all bonus clean fclean re
