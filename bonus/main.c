/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** main
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ncurses.h>
#include "sokoban.h"
#include <signal.h>
#include <time.h>
#include <stdio.h>

void maperror(char *buffer)
{
    int j = 0;
    int r = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        j++;
    for (int i = j+1; buffer[i] != '\0'; i++) {
        r++;
        if (buffer[i+1] == '\n' && r != j)
            exit (84);
        if (buffer[i] == '\n')
            r = 0;
    }
    return;
}

int readmap(char *map, int size, int fd)
{
    char *buffer = malloc(sizeof(char *) * size);
    variable v = mapsandnbr(size, fd, v);

    v = completegame(v, fd, buffer, size);
    while (checknumbero(v.newmap, v.nbr, &v) != 0 && v.r != 'y') {
        v.r = printmap(v.newmap, v.r, v.nbr, v);
        if (v.r == ' ')
            v.newmap = resetmap(v.newmap, v.nbr, size, buffer);
        if (spaceandlose(v, fd, map, size) == -1) {
            v.r = -1;
            break;
        }
    }
    free(buffer);
    free(v.newmap);
    free(v.mapo);
    if (v.r == 2)
        return (2);
    return (loseorwin(v.r, v.nbr, v.newmap));
}

void description(void)
{
    my_putstr("USAGE :\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION :\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls, ");
    my_putstr("'P' for the player, \n     'X' for boxes and 'O' ");
    my_putstr("for storage locations. \n");
    exit(0);
}

int my_pop(char *message, char *mess, char *space)
{
    int key = -1;
    int r = 1;

    noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    while (key != 'y') {
        if (key == KEY_LEFT || key == KEY_UP && r == 2)
            r = 1;
        if (key == KEY_RIGHT)
            r = 0;
        if (key == KEY_DOWN)
            r = 2;
        menu(message, mess, space);
        othermenusurvival("1 player :", "2 player :", r);
        key = getch();
        if (key == '\n')
            return (r);
    }
    return (3);
}

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    struct stat sb;
    int r = 0;

    errorarg(ac, av[1], fd, av[2]);
    stat(av[1], &sb);
    checksizeanderrors(av[1], fd, sb.st_size);
    checkfile(fd, sb.st_size, av[1]);
    checkcolor(ac, av, fd, sb.st_size);
    r = my_pop("My_sokoban :", "Press enter to start, Press y to exit.",
        "Press space_bar to reset the game.");
    if (r == 1) {
        clear();
        r = readmap(av[1], sb.st_size, fd);
    } else if (r == 0)
        r = waitplayertwo(av[1], sb.st_size, fd);
    else if (r == 2)
        r = waitsurvival(av[1], sb.st_size, fd);
    winorlose(r, fd, av[1], sb.st_size);
}