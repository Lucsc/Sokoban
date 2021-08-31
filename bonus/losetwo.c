/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** losetwo
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

void gamewintwo(char **map, int nbr, char **maptwo, char *end)
{
    char *message = " = loser !";
    char *mess = " = winner !";
    int i = my_strlen(message);
    int k = my_strlen(mess);
    int w = my_strlen(end);
    int fd = my_strlen(maptwo[0]);

    init_pair(2, COLOR_RED, COLOR_RED);
    wattron(stdscr, COLOR_PAIR(2));
    box(stdscr, 0, 0);
    wattroff(stdscr, COLOR_PAIR(2));
    init_pair(13, COLOR_RED, COLOR_BLACK);
    printthemaptwo(maptwo, nbr);
    printthemapsecond(map, nbr);
    attron(A_BOLD | COLOR_PAIR(13));
    mvprintw((LINES / 2) - 2, COLS / 4 + fd - i - 1, message);
    mvprintw((LINES / 2) - 2, COLS / 1.5 + fd - i - 1, mess);
    mvprintw((LINES / 2) - 15, COLS / 2 - w / 2, end);
    attroff(A_BOLD | COLOR_PAIR(7));
}

void gamelosetwo(char **map, int nbr, char **maptwo, char *end)
{
    char *message = " = loser !";
    char *mess = " = winner !";
    int i = my_strlen(message);
    int k = my_strlen(mess);
    int w = my_strlen(end);
    int fd = my_strlen(maptwo[0]);

    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    wattron(stdscr, COLOR_PAIR(1));
    box(stdscr, 0, 0);
    wattroff(stdscr, COLOR_PAIR(1));
    init_pair(12, COLOR_BLUE, COLOR_BLACK);
    printthemaptwo(maptwo, nbr);
    printthemapsecond(map, nbr);
    attron(A_BOLD | COLOR_PAIR(12));
    mvprintw((LINES / 2) - 2, COLS / 1.5 + fd - i - 1, message);
    mvprintw((LINES / 2) - 2, COLS / 4 + fd - i - 1, mess);
    mvprintw((LINES / 2) - 15, COLS / 2 - w / 2, end);
    attroff(A_BOLD | COLOR_PAIR(12));
}

int loseorwintwo(int r, int nbr, char **map, variable v)
{
    char *end = "Press 'y' to exit, Press 'space' to reset";

    clear();
    if (r == -1) {
        while (r != 'y') {
            gamelosetwo(map, nbr, v.maptwo, end);
            r = getch();
            if (r == ' ')
                return (2);
        }
        return (1);
    }
    if (r != 'y' && r == -2) {
        while (r != 'y') {
            gamewintwo(map, nbr, v.maptwo, end);
            r = getch();
            if (r == ' ')
                return (2);
        }
    }
}

void freethings(char *buffer, variable *v)
{
    free(buffer);
    free(v->newmap);
    free(v->mapo);
    free(v->mapotwo);
    free(v->maptwo);
}

int spaceandlosetwo(variable v, int fd, char *map, int size)
{
    if (checklose(v.maptwo, v.nbr, v.mapo, &v) == -1) {
        v.r = -2;
        return (-1);
    }
    if (checklose(v.newmap, v.nbr, v.mapo, &v) == -1) {
        v.r = -1;
        return (-1);
    }
    return (0);
}