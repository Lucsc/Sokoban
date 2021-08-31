/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** secondplayer
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

char **movesecondplayer(char **map, int k, int nbr, variable v)
{
    if (k == 'z') {
        k = KEY_UP;
        map = searchfind(map, k, nbr, &v);
    }
    if (k == 'q') {
        k = KEY_LEFT;
        map = searchfind(map, k, nbr, &v);
    }
    if (k == 's') {
        k = KEY_DOWN;
        map = searchfind(map, k, nbr, &v);
    }
    if (k == 'd') {
        k = KEY_RIGHT;
        map = searchfind(map, k, nbr, &v);
    }
    return (map);
}

void hashtagandxsecond(int fd, int w, int y, char map)
{
    if (map == '#')
    {
        attron(A_BOLD | COLOR_PAIR(7));
        mvaddch(LINES / 2 + y, COLS / 1.5 - fd + w, ' ');
        attroff(A_BOLD | COLOR_PAIR(7));
    }
    if (map == 'X')
    {
        attron(A_BOLD | COLOR_PAIR(9));
        mvaddch(LINES / 2 + y, COLS / 1.5 - fd + w, map);
        attroff(A_BOLD | COLOR_PAIR(9));
    }
}

void pandoandspacesecond(int fd, int w, int y, char map)
{
    if (map == 'P') {
        attron(A_BOLD);
        mvaddch(LINES / 2 + y, COLS / 1.5 - fd + w, map);
        attroff(A_BOLD);
    }
    if (map == 'O') {
        attron(A_BOLD | COLOR_PAIR(8));
        mvaddch(LINES / 2 + y, COLS / 1.5 - fd + w, map);
        attroff(A_BOLD | COLOR_PAIR(8));
    }
    if (map == ' ') {
        attron(A_BOLD);
        mvaddch(LINES / 2 + y, COLS / 1.5 - fd + w, map);
        attroff(A_BOLD);
    }
}

char **printthemapsecond(char **map, int nbr)
{
    int y = 0;
    int fd = my_strlen(map[0]) - 10;

    init_pair(7, COLOR_RED, COLOR_RED);
    init_pair(8, COLOR_YELLOW, COLOR_BLACK);
    init_pair(9, COLOR_BLUE, COLOR_BLACK);
    init_pair(10, COLOR_RED, COLOR_BLACK);
    attron(A_BOLD | COLOR_PAIR(10));
    mvprintw(LINES / 2 - 2, COLS / 1.5 - fd, "Player 2:");
    attroff(A_BOLD | COLOR_PAIR(10));
    for (int j = 0; j != nbr; j++, y++) {
        for (int i = 0, w = 0; map[j][i] != '\n'; i++, w++) {
            hashtagandxsecond(fd, w, y, map[j][i]);
            pandoandspacesecond(fd, w, y, map[j][i]);
        }
    }
}

void makeboxsecond(void)
{
    init_pair(1, COLOR_CYAN, COLOR_CYAN);
    wattron(stdscr, COLOR_PAIR(1));
    box(stdscr, '#', '#');
    wattroff(stdscr, COLOR_PAIR(1));
}