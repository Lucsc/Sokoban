##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc libmy.a $(OBJ)
	cp my.h ../../include/
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
