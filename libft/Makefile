# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:33:13 by saneveu           #+#    #+#              #
#    Updated: 2018/11/08 18:27:31 by saneveu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OPTS = -c -Wall -Werror -Wextra -I$(INCLUDE)

INCLUDE = libft.h

SRC1 = *.c

SRC2 = *.o

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