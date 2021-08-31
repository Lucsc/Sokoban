/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** movebox
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

void othermenu(char *message, char *mess, int k)
{
    int i = my_strlen(message);
    int r = my_strlen(mess);

    if (k == 1) {
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2 + 6, COLS / 2 - i / 2 - 10, message);
        attroff(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2 + 6, COLS / 2 - r / 2 + 10, mess);
    } else {
        mvprintw(LINES / 2 + 6, COLS / 2 - i / 2 - 10, message);
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(LINES / 2 + 6, COLS / 2 - r / 2 + 10, mess);
        attroff(A_BOLD | A_UNDERLINE);
    }
}

char **moveboxright(char **map, int r, int i, int j)
{
    if (r == KEY_RIGHT) {
        if (map[i][j+2] == 'X') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i][j+2] == '#') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i][j] != 'O')
            map[i][j] = ' ';
        map[i][j+1] = 'P';
        map[i][j+2] = 'X';
    }
    return (map);
}

char **moveboxleft(char **map, int r, int i, int j)
{
    if (r == KEY_LEFT) {
        if (map[i][j-2] == '#') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i][j-2] == 'X') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i][j] != 'O')
            map[i][j] = ' ';
        map[i][j-1] = 'P';
        map[i][j-2] = 'X';
    }
    return (map);
}

char **moveboxup(char **map, int r, int i, int j)
{
    if (r == KEY_UP) {
        while (map[i-2][j] == 'X') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i-2][j] == '#') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i][j] != 'O')
            map[i][j] = ' ';
        map[i-1][j] = 'P';
        map[i-2][j] = 'X';
    }
    return (map);
}

char **moveboxdown(char **map, int r, int i, int j)
{
    if (r == KEY_DOWN) {
        while (map[i+2][j] == 'X') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i+2][j] == '#') {
            map[i][j] = 'P';
            return (map);
        }
        if (map[i][j] != 'O')
            map[i][j] = ' ';
        map[i+1][j] = 'P';
        map[i+2][j] = 'X';
    }
    return (map);
}