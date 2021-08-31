/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** reset
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

void printmenu(char *message, char *mess, char *survival)
{
    int i = my_strlen(message);
    int w = my_strlen(survival);
    int r = my_strlen(mess);

    mvprintw(LINES / 2 + 6, COLS / 2 - i / 2 - 10, message);
    mvprintw(LINES / 2 + 6, COLS / 2 - r / 2 + 10, mess);
    attron(A_BOLD | A_UNDERLINE);
    mvprintw(LINES / 2 + 8, COLS / 2 - w / 2, survival);
    attroff(A_BOLD | A_UNDERLINE);
}

void othermenusurvival(char *message, char *mess, int k)
{
    char *survival = "Survival :";
    int w = my_strlen(survival);
    int i = my_strlen(message);
    int r = my_strlen(mess);

    if (k == 1) {
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2 + 6, COLS / 2 - i / 2 - 10, message);
        attroff(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2 + 6, COLS / 2 - r / 2 + 10, mess);
        mvprintw(LINES / 2 + 8, COLS / 2 - w / 2, survival);
    } else if (k == 0) {
        mvprintw(LINES / 2 + 6, COLS / 2 - i / 2 - 10, message);
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2 + 6, COLS / 2 - r / 2 + 10, mess);
        attroff(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2 + 8, COLS / 2 - w / 2, survival);
    } else if (k == 2)
        printmenu(message, mess, survival);
}

char **resetmap(char **map, int nbr, int size, char *buffer)
{
    map = fillmap(buffer, map, nbr, size);
    return (map);
}

variable checkreset(variable v, int size, char *buffer)
{
    if (v.k == ' ')
        v.maptwo = resetmap(v.maptwo, v.nbr, size, buffer);
    if (v.r == ' ')
        v.newmap = resetmap(v.newmap, v.nbr, size, buffer);
    return (v);
}