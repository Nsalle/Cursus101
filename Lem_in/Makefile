# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/27 18:49:19 by nsalle       #+#   ##    ##    #+#        #
#    Updated: 2019/11/20 17:39:15 by nsalle      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= 	lem-in

CC 		= 	gcc
CFLAGS 	+= 	-Wextra -Werror -Wall

SRC 	= 	src/main.c		  		\
			src/lem_parsing.c 		\
			src/testing.c     		\
			src/error.c 	  		\
			src/parsing_tools.c		\
			src/lem_parse_rooms.c 	\
			src/lem_parse_coords.c 	\
			src/visu/visu_lemin.c	\
			src/visu/print.c		\
			src/visu/free_vs.c		\
			src/visu/init_items.c	\
			src/visu/bresenham.c	\
			src/visu/settings.c		\
			src/visu/ant_movement.c	

OBJ		=	$(SRC:.c=.o)

INC		=	-I./$(LFTDIR) -I.

LFTDIR	=	libft
LFT		=	-L $(LFTDIR) -lft

RM		=	/bin/rm

all: LFTC $(NAME)

LFTC:
	@$(MAKE) -C $(LFTDIR)

$(NAME): $(OBJ) lem_in.h $(LFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(INC) $(LFT) -L lib -l SDL2-2.0.0 -lSDL2_image-2.0.0 -lSDL2_ttf-2.0.0 $(OBJ) -o $(NAME)
	@printf "\n|-> \033[32m$(NAME) compiled\033[0m\n\n"

clean:
	@$(MAKE) -C $(LFTDIR) $@
	@$(RM) -rf $(OBJ)
	@printf "|-> \033[31mobjects removed\033[0m\n"

fclean: clean
	@$(MAKE) -C $(LFTDIR) $@
	@$(RM) -f $(NAME)
	@printf "|-> \033[31m$(NAME) deleted\033[0m\n"

re: fclean all

.SILENT: $(OBJ)
.PHONY: all clean fclean re