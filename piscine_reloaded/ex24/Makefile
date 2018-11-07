# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 14:26:51 by saneveu           #+#    #+#              #
#    Updated: 2018/09/18 20:34:07 by saneveu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OPTS = -c -I$(INCLUDE) 

SRC1 = ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_putchar.c ./srcs/ft_swap.c

SRC2 = ft_putchar.o ft_strlen.o ft_strcmp.o ft_putstr.o ft_swap.o

INCLUDE = /includes

all: $(NAME)

$(NAME):
	@gcc $(OPTS) $(SRC1)
	@ar rc $(NAME) $(SRC2)
	@ranlib $(NAME)

clean: 
	@/bin/rm -f $(SRC2)

fclean:
	@/bin/rm -rf $(NAME) $(SRC2)

re: fclean all
