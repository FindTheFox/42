# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 10:45:51 by saneveu           #+#    #+#              #
#    Updated: 2018/11/06 15:34:47 by saneveu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = ./srcs/ft_display_file.c ./srcs/ft_putchar.c 

INCLUDE = ./include/lib_display.h

OPTS = -o $(NAME) -Wall -Werror -Wextra

OPTS2 = -I $(INCLUDE)

all: $(NAME)

$(NAME):
		@gcc $(OPTS) $(OPTS2) $(SRC)

clean:
		@/bin/rm -f *.o

fclean:
		@/bin/rm -f $(NAME) 

re: fclean all
