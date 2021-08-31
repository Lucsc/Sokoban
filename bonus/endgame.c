/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** endgame
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

void makebox(void)
{
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    wattron(stdscr, COLOR_PAIR(1));
    box(stdscr, '#', '#');
    wattroff(stdscr, COLOR_PAIR(1));
}

void pandoandspace(int fd, int w, int y, char map)
{
    if (map == 'P') {
        attron(A_BOLD);
        mvaddch(LINES / 2 + y, COLS / 2 - fd + w, map);
        attroff(A_BOLD);
    }
    if (map == 'O') {
        attron(A_BOLD | COLOR_PAIR(4));
        mvaddch(LINES / 2 + y, COLS / 2 - fd + w, map);
        attroff(A_BOLD | COLOR_PAIR(4));
    }
    if (map == ' ') {
        attron(A_BOLD);
        mvaddch(LINES / 2 + y, COLS / 2 - fd + w, map);
        attroff(A_BOLD);
    }
}

void hashtagandx(int fd, int w, int y, char map)
{
    if (map == '#')
    {
        attron(A_BOLD | COLOR_PAIR(3));
        mvaddch(LINES / 2 + y, COLS / 2 - fd + w, ' ');
        attroff(A_BOLD | COLOR_PAIR(3));
    }
    if (map == 'X')
    {
        attron(A_BOLD | COLOR_PAIR(6));
        mvaddch(LINES / 2 + y, COLS / 2 - fd + w, map);
        attroff(A_BOLD | COLOR_PAIR(6));
    }
}

char **printthemap(char **map, int nbr)
{
    int y = 0;
    int fd = my_strlen(map[0]) - 10;

    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    for (int j = 0; j != nbr; j++, y++) {
        for (int i = 0, w = 0; map[j][i] != '\n'; i++, w++) {
            hashtagandx(fd, w, y, map[j][i]);
            pandoandspace(fd, w, y, map[j][i]);
        }
    }
}

int loseorwin(int r, int nbr, char **map)
{
    char *end = "Press 'y' to exit, Press 'space' to reset";

    clear();
    if (r == -1) {
        while (r != 'y') {
            gamelose(map, nbr, "You lose !", end);
            r = getch();
            if (r == ' ')
                return (2);
        }
        return (1);
    }
    if (r != 'y') {
        while (r != 'y') {
            gamewin(map, nbr, "You win !", end);
            r = getch();
            if (r == ' ')
                return (2);
        }
    }
}