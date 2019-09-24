# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 11:35:41 by ghtouman          #+#    #+#              #
#    Updated: 2019/02/12 13:02:12 by ghtouman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
IDIR = ./includes/
NAME = ghtouman.filler
SRC_PATH = ./srcs/
LIB_PATH = ./libft/
LIB = libft/libft.a

SRC = $(SRC_PATH)gen_map.c			\
		$(SRC_PATH)get_map_info.c	\
		$(SRC_PATH)get_piece.c		\
		$(SRC_PATH)weight_filler.c	\
		$(SRC_PATH)get_player_info.c\
		$(SRC_PATH)filler.c			\
		$(SRC_PATH)find_pos.c		\
		$(SRC_PATH)place_piece.c

OBJ = $(SRC:.c=.o)

all:$(NAME)
$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) $(LIB) -I $(LIB_PATH) -o $(NAME)

%.o: %.c
	gcc -c $(FLAG) $< -o $@ -I$(IDIR)

$(OBJ) : $(IDIR)filler.h

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

libft/libft.a:
	make -C libft
