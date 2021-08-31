/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** twoplayer
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

variable mapsandnbrtwo(int size, int fd, variable v)
{
    v.newmap = malloc(sizeof(char *) * size);
    v.mapo = malloc(sizeof(char *) * size);
    v.maptwo = malloc(sizeof(char *) * size);
    v.mapotwo = malloc(sizeof(char *) * size);
    v.nbr = 0;
    v.r = 0;
    v.w = 0;
    return (v);
}

void hashtagandxtwo(int fd, int w, int y, char map)
{
    if (map == '#')
    {
        attron(A_BOLD | COLOR_PAIR(3));
        mvaddch(LINES / 2 + y, COLS / 4 - fd + w, ' ');
        attroff(A_BOLD | COLOR_PAIR(3));
    }
    if (map == 'X')
    {
        attron(A_BOLD | COLOR_PAIR(6));
        mvaddch(LINES / 2 + y, COLS / 4 - fd + w, map);
        attroff(A_BOLD | COLOR_PAIR(6));
    }
}

void pandoandspacetwo(int fd, int w, int y, char map)
{
    if (map == 'P') {
        attron(A_BOLD);
        mvaddch(LINES / 2 + y, COLS / 4 - fd + w, map);
        attroff(A_BOLD);
    }
    if (map == 'O') {
        attron(A_BOLD | COLOR_PAIR(4));
        mvaddch(LINES / 2 + y, COLS / 4 - fd + w, map);
        attroff(A_BOLD | COLOR_PAIR(4));
    }
    if (map == ' ') {
        attron(A_BOLD);
        mvaddch(LINES / 2 + y, COLS / 4 - fd + w, map);
        attroff(A_BOLD);
    }
}

void menutwoplayer(char *message, char *mess, char *space)
{
    int i = my_strlen(message);
    int r = my_strlen(mess);
    int k = my_strlen(space);

    wattron(stdscr, COLOR_PAIR(1));
    box(stdscr, 0, 0);
    wattroff(stdscr, COLOR_PAIR(1));
    attron(A_BOLD | A_UNDERLINE);
    mvprintw(LINES / 2 + 4, COLS / 2 - k / 2, space);
    attroff(A_BOLD | A_UNDERLINE);
    attron(A_BOLD);
    mvprintw(LINES / 2 + 2, COLS / 2 - r / 2, mess);
    mvprintw(LINES / 2, COLS / 2 - i / 2, message);
    attroff(A_BOLD);
}

int waitplayertwo(char *av, int size, int fd)
{
    char *message = "Player 1 is left, play with z/q/s/d.";
    char *mess = "Player 2 is right, play with up/left/down/right.";
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
    return (readmapsecond(av, size, fd));
}