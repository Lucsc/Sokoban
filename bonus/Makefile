##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC     =		main.c \
				map.c \
				key.c \
				lose.c \
				completegame.c \
				movebox.c \
				endgame.c \
				win.c \
				twoplayer.c \
				othertwoplayer.c \
				number.c \
				secondplayer.c \
				losetwo.c \
				reset.c \
				survival.c \
				score.c \
				getscore.c \
				mapsurvival.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       ./my_sokoban

all:    $(NAME)

$(NAME):        $(OBJ)
	make -C lib/my/ all
	gcc -o $(NAME) $(OBJ) -L lib/my/ -lmy -lncurses

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm lib/libmy.a
	rm lib/my/libmy.a
	rm -f $(NAME)

re:	fclean all
