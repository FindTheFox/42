# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 18:53:52 by saneveu           #+#    #+#              #
#    Updated: 2020/02/16 02:19:26 by saneveu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
TUR		=	\033[36m
WHITE	=	\033[37m
END		=	\033[0m

UP 		=	\033[A
CUT 	=	\033[K

# project
NAME	=	cube3D
OS		=	$(shell uname)

# directories
SRCDIR	=	./srcs
INCDIR	=	./includes
OBJDIR	=	./obj

# src / obj files
SRC		=	main.c \
			draw.c \
			event.c \
			cube_point.c \
			exit.c \
			init_matrice.c \
			init_sdl.c \
			fill_triangle.c \
			vector_calc.c \
			color.c \
			cube3d.c \
			init_data.c \
			line.c
	
INC		=	cube3d.h

OBJ		=	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))
HEADER	=	$(addprefix $(INCDIR)/,$(INC))

# compiler
CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror -Ofast -march=native

ifeq ($(OS), Linux)
	SDL		=	-lSDL2-2.0
	DIRSDL	=	
else
	SDL		=	-F ~/Library/Frameworks -framework SDL2
	DIRSDL	=	-I ./SDL
endif 

# ft library
FT		=	./libft/
FT_LIB	=	$(addprefix $(FT),libft.a)

all: 		obj $(FT_LIB) $(NAME)

obj:
			mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c $(HEADER)
			@echo "${TUR}compiling [$@] ...${END}"
			@$(CC) $(CFLAGS) -I $(INCDIR) -c -o $@ $< $(DIRSDL)
			@printf "$(UP)$(CUT)"

$(FT_LIB):
			@$(MAKE) -C $(FT)
			@echo "${GREEN}[LIBRARY COMPILED]${END}"

$(NAME):	$(OBJ) $(FT_LIB)
			@$(CC) $(CFLAGS) $(OBJ) $(FT_LIB) $(SDL) -lm -lpthread -o $@
			@echo "${GREEN}[$@ COMPILED]${END}"

clean:
			@/bin/rm -rf $(OBJDIR)
			@$(MAKE) -C $(FT) clean
			@echo "${PURPLE}[.o deleted]${END}"

fclean:		clean
			@/bin/rm -rf $(NAME)
			@$(MAKE) -C $(FT) fclean
			@echo "${RED}[$(NAME) deleted]${END}"
			@echo "${RED}[$(LIB) deleted]${END}"

re:			fclean all

SDL2:
			brew install sdl2
			brew link sdl2
			brew install sdl2_ttf
			brew link sdl2_ttf
			brew install sdl2_mixer
			brew link sdl2_mixer
			cp -rf framework/SDL2_mixer.framework ~/Library/Frameworks
			cp -rf framework/SDL2_ttf.framework ~/Library/Frameworks
			cp -rf framework/SDL2.framework ~/Library/Frameworks

.PHONY:		all clean fclean re
