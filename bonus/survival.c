/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** survival
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

void printbuffer(char *buffer, int j, int w, int y)
{
    if (buffer[j] == 'N' && buffer[j+1] == 'E' && buffer[j+2] == 'W') {
        attron(COLOR_PAIR(15));
        mvaddch(LINES / 2 + y, COLS / 2 + w, buffer[j]);
    } else if (buffer[j-1] == 'N' && buffer[j] == 'E')
        mvaddch(LINES / 2 + y, COLS / 2 + w, buffer[j]);
    else if (buffer[j-1] == 'E' && buffer[j] == 'W') {
        mvaddch(LINES / 2 + y, COLS / 2 + w, buffer[j]);
        attroff(COLOR_PAIR(15));
    } else
        mvaddch(LINES / 2 + y, COLS / 2 + w, buffer[j]);
    return;
}

variable mapssurvival(variable v, int fd, char *buffer, int size)
{
    clear();
    read(fd, buffer, size);
    for (int j = 0; buffer[j] != '\0'; j++)
        if (buffer[j] == '\n')
            v.nbr++;
    v.newmap = fillmap(buffer, v.newmap, v.nbr, size);
    v.mapo = fillmap(buffer, v.mapo, v.nbr, size);
    close(fd);
    return (v);
}

int readmapsurvival(char *map, int size, int fd, int i)
{
    fd = survivalfile(i, fd);
    char *buffer = malloc(sizeof(char *)* size);
    variable v = mapsandnbr(size, fd, v);

    v = mapssurvival(v, fd, buffer, size);
    while (checknumbero(v.newmap, v.nbr, &v) != 0 && v.r != 'y' && v.r != ' ') {
        v.r = printmap(v.newmap, v.r, v.nbr, v);
        v.w = spaceandlose(v, fd, map, size);
        if (v.w == -1)
            break;
    }
    free(buffer);
    free(v.newmap);
    free(v.mapo);
    if (v.w == -1 || v.r == 'y' || v.r == ' ')
        scoresurv(i, fd);
    i++;
    if (i < 15)
        readmapsurvival(map, size, fd, i);
}

int waitsurvival(char *av, int size, int fd)
{
    char *message = "You have 10 maps to complete.";
    char *mess = "If you try to reset the game, you'll lose.";
    int r  = 1;
    int key = -1;

    clear();
    while (key != 'y') {
        if (key == KEY_LEFT)
            r = 1;
        if (key == KEY_RIGHT)
            r = 0;
        menutwoplayer(message, mess, "Are you ready ?");
        othermenu("Yes.", "No.", r);
        key = getch();
        if (key == '\n' && r == 1)
            break;
        if (key == '\n' && r == 0)
            return (r);
    }
    launch("Start after countdown !", 2);
    return (readmapsurvival(av, size, fd, 0));
}