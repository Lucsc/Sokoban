/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** map
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

void enlargeterminal(char *buffer, int nbr, int size, char *message)
{
    char *mapone = malloc(sizeof(char *) * size);
    int len = my_strlen(message);
    int r;

    for (int r = 0; buffer[r-1] != '\n'; r++)
        mapone[r] = buffer[r];
    r = my_strlen(mapone);
    while ((LINES/2 - nbr/2)*(COLS/2-r/2) < size - 10) {
        mvprintw(LINES / 2, COLS / 2 - len / 2, message);
        refresh();
    }
    clear();
    free(mapone);
    return;
}

void checkfile(int fd, int size, char *av)
{
    char *buffer = malloc(sizeof(char *) * size);
    char *message = "You need to enlarge the terminal.";
    int nbr = 0;

    initscr();
    read(fd, buffer, size);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '#' && buffer[i] != 'P'
            && buffer[i] != 'O' && buffer[i] != 'X' && buffer[i] != '\n') {
            endwin();
            exit (84);
        }
        if (buffer[i] == '\n')
            nbr++;
    }
    enlargeterminal(buffer, nbr, size, message);
    free (buffer);
    close(fd);
    fd = open(av, O_RDONLY);
}

int errorarg(int ac, char *av, int fd, char *avr)
{
    if (ac != 2) {
        close(fd);
        my_putstr("1 argument is needed to use ./my_sokoban ");
        my_putstr("and you gave ");
        my_putchar(ac + '0' - 1);
        my_putstr(".\nTry ./my_sokoban -h for more information.\n");
        exit (84);
    }
    if (my_strcmp(av, "-h") == 0)
        description();
    if (fd == -1) {
        close(fd);
        my_putstr("Wrong argument.\n");
        my_putstr("Try ./my_sokoban -h for more information.\n");
        exit (84);
    }
    return (0);
}

int printmap(char **newmap, int r, int nbr, variable v)
{
    int y = 0;
    keypad(stdscr, TRUE);

    makebox();
    clear();
    printthemap(newmap, nbr);
    y = 0;
    r = getch();
    if (r == KEY_LEFT || r == KEY_UP || r == KEY_RIGHT || r == KEY_DOWN)
        newmap = searchfind(newmap, r, nbr, &v);
    refresh();
    return (r);
}

char **fillmap(char *buffer, char **newmap, int nbr, int size)
{
    int col = 0;
    int r = 0;

    for (int j = 0; buffer[j-1] != '\n'; j++)
        col++;
    for (int j = 0; j != nbr; j++)
        newmap[j] = malloc(sizeof(char *) * size);
    for (int i = 0; i != nbr; i++) {
        for (int j = 0; j != col; j++, r++) {
            newmap[i][j] = buffer[r];
        }
    }
    return (newmap);
}