##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile of the my_ls in order to generate the binary.
##

SRC_DIR =	./SRC

SRC	=	$(SRC_DIR)/move.c		\
		$(SRC_DIR)/my_arraylen.c	\
		$(SRC_DIR)/count.c		\
		$(SRC_DIR)/my_strlen.c		\
		$(SRC_DIR)/my_strcpy.c		\
                $(SRC_DIR)/endgame.c		\
                $(SRC_DIR)/searchPlayer.c	\
                $(SRC_DIR)/sokoban.c		\
		$(SRC_DIR)/my_putstr.c		\
		$(SRC_DIR)/my_putchar.c		\
		$(SRC_DIR)/setArray.c		\
		$(SRC_DIR)/main.c

CFLAGS	=	-W -Werror -Wall -Wextra

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

all:	$(NAME) clean

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lcurses
	rm $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

