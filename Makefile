#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljouanne <ljouanne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/18 20:49:59 by ljouanne          #+#    #+#              #
#    Updated: 2014/09/18 21:39:31 by gpueo--g         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq

SRC = 	./bsq.c \
		./ft.c \
		./ggrid.c \
		./grid.c \
		./matrix.c \
		./matrixx.c \
		./matrixxx.c \
		./str.c

OBJ =	./bsq.o \
		./ft.o \
		./ggrid.o \
		./grid.o \
		./matrix.o \
		./matrixx.o \
		./matrixxx.o \
		./str.o

HDR =	./ft.h

HDRG =	./ft.h.gch

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(HDR) $(SRC);
	gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME);

clean:
	rm -f $(OBJ);
	rm -f $(HDRG);

fclean: clean
	rm -f $(NAME);

re: fclean all
