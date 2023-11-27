# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 15:35:45 by jpajuelo          #+#    #+#              #
#    Updated: 2023/08/04 16:57:22 by jpajuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c utils.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

OBJ = $(SRC:.c=.o)

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		

all : $(NAME)

$(NAME) : $(OBJ)
		@make re -C ./libft
		@$(CC) $(OBJ) -Llibft -lft -o $(NAME)
		

clean : 
		@make clean -C ./libft
		$(RM) $(OBJ)

fclean : clean
		@make fclean -C ./libft
		$(RM) $(NAME)

re : fclean all