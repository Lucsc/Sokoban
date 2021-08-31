/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** othertwoplayer
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

char **printthemaptwo(char **map, int nbr)
{
    int y = 0;
    int fd = my_strlen(map[0]) - 10;

    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    attron(A_BOLD | COLOR_PAIR(11));
    mvprintw(LINES / 2 - 2, COLS / 4 - fd, "Player 1:");
    attroff(A_BOLD | COLOR_PAIR(11));
    for (int j = 0; j != nbr; j++, y++) {
        for (int i = 0, w = 0; map[j][i] != '\n'; i++, w++) {
            hashtagandxtwo(fd, w, y, map[j][i]);
            pandoandspacetwo(fd, w, y, map[j][i]);
        }
    }
}

variable printmaptwo(char **newmap, int r, int nbr, variable v)
{
    int y = 0;
    keypad(stdscr, TRUE);
    noecho();

    makeboxsecond();
    printthemaptwo(v.maptwo, nbr);
    printthemapsecond(newmap, nbr);
    y = 0;
    r = getch();
    if (r == KEY_LEFT || r == KEY_UP || r == KEY_RIGHT || r == KEY_DOWN)
        newmap = searchfind(newmap, r, nbr, &v);
    printthemaptwo(v.maptwo, nbr);
    refresh();
    v.k = getch();
    v.r = r;
    v.maptwo = movesecondplayer(v.maptwo, v.k, nbr, v);
    printthemapsecond(newmap, nbr);
    refresh();
    return (v);
}

variable completegametwo(variable v, int fd, char *buffer, int size)
{
    launch("Start after countdown !", 1);
    clear();
    read(fd, buffer, size);
    for (int j = 0; buffer[j] != '\0'; j++)
        if (buffer[j] == '\n')
            v.nbr++;
    v.newmap = fillmap(buffer, v.newmap, v.nbr, size);
    v.mapo = fillmap(buffer, v.mapo, v.nbr, size);
    v.maptwo = fillmap(buffer, v.maptwo, v.nbr, size);
    v.mapotwo = fillmap(buffer, v.mapotwo, v.nbr, size);
    close(fd);
    return (v);
}

int readmapsecond(char *map, int size, int fd)
{
    char *buffer = malloc(sizeof(char *) * size);
    variable v = mapsandnbrtwo(size, fd, v);

    v = completegametwo(v, fd, buffer, size);
    while (checknumbero(v.newmap, v.nbr, &v) != 0 && v.r != 'y'
            && v.k != 'y' && checknumbero(v.maptwo, v.nbr, &v) != 0) {
        v = printmaptwo(v.newmap, v.r, v.nbr, v);
        v = checkreset(v, size, buffer);
        v.w = spaceandlosetwo(v, fd, map, size);
        if (v.w == -1 || v.w == -2)
            break;
    }
    if (checknumbero(v.maptwo, v.nbr, &v) == 0)
        v.w = -1;
    if (checknumbero(v.newmap, v.nbr, &v) == 0)
        v.w = -2;
    freethings(buffer, &v);
    if (v.r == 'y' || v.k == 'y')
        return (0);
    return (loseorwintwo(v.w, v.nbr, v.newmap, v));
}

int checkcolor(int ac, char **av, int fd, int size)
{
    if (has_colors() == FALSE) {
        endwin();
        exit(84);
    }
    start_color();
}