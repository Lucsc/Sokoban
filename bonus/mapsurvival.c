/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** mapsurvival
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
#include <curses.h>

int morefile(int i, int fd)
{
    if (i == 8)
        return (fd = open("maps/map9", O_RDONLY));
    if (i == 9)
        return (fd = open("maps/map10", O_RDONLY));
}

int survivalfile(int i, int fd)
{
    if (i == 10)
        scoresurv(i, fd);
    clear();
    close (fd);
    if (i == 0)
        return (fd = open("maps/map1", O_RDONLY));
    if (i == 1)
        return (fd = open("maps/map2", O_RDONLY));
    if (i == 2)
        return (fd = open("maps/map3", O_RDONLY));
    if (i == 3)
        return (fd = open("maps/map4", O_RDONLY));
    if (i == 4)
        return (fd = open("maps/map5", O_RDONLY));
    if (i == 5)
        return (fd = open("maps/map6", O_RDONLY));
    if (i == 6)
        return (fd = open("maps/map7", O_RDONLY));
    if (i == 7)
        return (fd = open("maps/map8", O_RDONLY));
    return (morefile(i, fd));
}