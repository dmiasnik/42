# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmiasnik <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 11:57:13 by dmiasnik          #+#    #+#              #
#    Updated: 2023/11/12 13:05:16 by dmiasnik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	
	make -C ./libft
	cc $(FLAGS) server.c libft/libft.a -o $(SERVER)
	cc $(FLAGS) client.c libft/libft.a -o $(CLIENT)

bonus:
	make -C ./libft
	cc $(FLAGS) server_bonus.c libft/libft.a -o $(SERVER)
	cc $(FLAGS) client_bonus.c libft/libft.a -o $(CLIENT)

clean:	
	make clean -C ./libft
	rm -f $(SERVER) $(CLIENT)

fclean:	
	make fclean -C ./libft 
	make clean

re: fclean all

.PHONY:     all clean fclean re
