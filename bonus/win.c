/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** win
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

void checksizeanderrors(char *av, int fd, int size)
{
    if (size == 0)
        exit (84);
    finderror(av, fd, size);
}

void winorlose(int r, int fd, char *av, int size)
{
    clear();
    if (r == 2) {
        fd = open(av, O_RDONLY);
        r = readmap(av, size, fd);
    }
    endwin();
    if (r == 1)
        exit (1);
    exit (0);
}

void menu(char *message, char *mess, char *space)
{
    int i = my_strlen(message);
    int r = my_strlen(mess);
    int k = my_strlen(space);

    wattron(stdscr, COLOR_PAIR(1));
    box(stdscr, 0, 0);
    wattroff(stdscr, COLOR_PAIR(1));
    attron(A_BOLD | A_UNDERLINE);
    mvprintw(LINES / 2, COLS / 2 - i / 2, message);
    attroff(A_BOLD | A_UNDERLINE);
    attron(A_BOLD);
    mvprintw(LINES / 2 + 2, COLS / 2 - r / 2, mess);
    mvprintw(LINES / 2 + 4, COLS / 2 - k / 2, space);
    attroff(A_BOLD);
}

void gamelose(char **map, int nbr, char *message, char *end)
{
    int i = my_strlen(message);
    int w = my_strlen(end);

    init_pair(1, COLOR_RED, COLOR_RED);
    wattron(stdscr, COLOR_PAIR(1));
    box(stdscr, 0, 0);
    wattroff(stdscr, COLOR_PAIR(1));
    init_pair(7, COLOR_RED, COLOR_WHITE);
    printthemap(map, nbr);
    attron(A_BOLD | COLOR_PAIR(7));
    mvprintw((LINES / 2) - 20, COLS / 2 - i / 2, message);
    mvprintw((LINES / 2) - 15, COLS / 2 - w / 2, end);
    attroff(A_BOLD | COLOR_PAIR(7));
}

void gamewin(char **map, int nbr, char *mess, char *end)
{
    int j = my_strlen(mess);
    int w = my_strlen(end);

    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    wattron(stdscr, COLOR_PAIR(2));
    box(stdscr, 0, 0);
    wattroff(stdscr, COLOR_PAIR(2));
    init_pair(7, COLOR_GREEN, COLOR_WHITE);
    printthemap(map, nbr);
    attron(A_BOLD | COLOR_PAIR(7));
    mvprintw(LINES / 2 - 20, COLS / 2 - j / 2, mess);
    mvprintw(LINES / 2 - 15, COLS / 2 - w / 2, end);
    attroff(A_BOLD | COLOR_PAIR(7));
}