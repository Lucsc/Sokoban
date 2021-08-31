/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** morekey
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <term.h>
#include <ncurses.h>
#include "sokoban.h"

int spaceandlose(variable v, int fd, char *map, int size)
{
    if (checklose(v.newmap, v.nbr, v.mapo, &v) == -1) {
        v.r = -1;
        return (-1);
    }
    return (0);
}

variable completegame(variable v, int fd, char *buffer, int size)
{
    launch("Start after countdown !", 1);
    read(fd, buffer, size);
    for (int j = 0; buffer[j] != '\0'; j++)
        if (buffer[j] == '\n')
            v.nbr++;
    v.newmap = fillmap(buffer, v.newmap, v.nbr, size);
    v.mapo = fillmap(buffer, v.mapo, v.nbr, size);
    close(fd);
    return (v);
}

variable mapsandnbr(int size, int fd, variable v)
{
    v.newmap = malloc(sizeof(char *) * size);
    v.mapo = malloc(sizeof(char *) * size);
    v.nbr = 0;
    v.r = 0;
    return (v);
}

void checkhashtag(char *buffer, int j)
{
    if (buffer[j] != '#')
        exit (84);
}

void checkmapfull(int fd, char *av, int size)
{
    char *buffer = malloc(sizeof(char *) * size);
    int i = 0;
    int r = 1;

    read(fd, buffer, size);
    for (int j = 0; buffer[j] != '\n'; j++, r++)
        checkhashtag(buffer, j);
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i+1] == '\n')
            checkhashtag(buffer, i);
        if (buffer[i-1] == '\n')
            checkhashtag(buffer, i);
    }
    i -= 2;
    for (; buffer[i] != '\n'; i--)
        checkhashtag(buffer, i);
    free(buffer);
    close(fd);
    fd = open(av, O_RDONLY);
}