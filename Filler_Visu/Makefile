# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nsalle <nsalle@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/07/17 00:24:24 by nsalle       #+#   ##    ##    #+#        #
#    Updated: 2019/07/17 02:36:58 by nsalle      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= 	nsvisu.filler

CC 		= 	gcc
CFLAGS 	+= 	-Wextra -Werror -Wall

SRC 	= 	main.c				\
			print.c				\
			print2.c
		
OBJ		=	$(SRC:.c=.o)

INC		=	-I./$(LFTDIR) -I.

LFTDIR	=	libft
LFT		=	-L $(LFTDIR) -lft

RM		=	/bin/rm

all: LFTC $(NAME)

LFTC:
	@$(MAKE) -C $(LFTDIR)

$(NAME): $(OBJ) visu.h $(LFTDIR)/libft.a
	@$(CC) $(CFLAGS) $(INC) $(LFT) $(OBJ) -o $(NAME)
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