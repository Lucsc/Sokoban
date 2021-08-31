/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** lose
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

void finderror(char *av, int fd, int size)
{
    char *buffer = malloc(sizeof(char *) * size);
    int r = 0;
    int j = 0;
    int k = 0;

    read(fd, buffer, size);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'X')
            r++;
        if (buffer[i] == 'O')
            k++;
        if (buffer[i] == 'P')
            j++;
    }
    maperror(buffer);
    close(fd);
    free(buffer);
    if (r != k || j == 0 || r == 0 || k == 0)
        exit (84);
    fd = open(av, O_RDONLY);
}

int checkwino(char **map, char **mapo, variable *v, int nbr)
{
    if (mapo[v->i][v->j] == 'O')
        return (1);
    return (0);
}

int checkaround(char **map, int nbr, int i, int j)
{
    int r = 0;

    for (; map[0][r] == ' ' || map[0][r] == '#' || map[0][r] == 'X'; r++) {
        if (map[0][r] == 'O')
            r++;
    }
    if (map[i][j] == 'X') {
        if (i == nbr - 1 || i == 0 || j == 0 || j == r - 1)
            return (-1);
        if (map[i+1][j] == '#' && map[i][j+1] == '#')
            return (-1);
        if (map[i+1][j] == '#' && map[i][j-1] == '#')
            return (-1);
        if (map[i-1][j] == '#' && map[i][j+1] == '#')
            return (-1);
        if (map[i-1][j] == '#' && map[i][j-1] == '#')
            return (-1);
    }
    return (0);
}

int checklose(char **map, int nbr, char **mapo, variable *v)
{
    int w = 0;
    int x = 0;

    for (int i = 0; i != nbr; i++) {
        for (int j = 0, r = 0; map[i][j] != '\n'; j++) {
            if (map[i][j] == 'X') {
                x++;
                v->i = i;
                v->j = j;
                r = checkwino(map, mapo, v, nbr);
            }
            if (r == 1)
                j++;
            if (checkaround(map, nbr, i, j) == -1)
                w++;
        }
    }
    if (w == x)
        return (-1);
    return (0);
}

int checknumbero(char **map, int nbr, variable *v)
{
    int number = 0;

    for (int i = 0; i != nbr; i++) {
        for (int j = 0; map[i][j] != '\n'; j++) {
            if (map[i][j] == 'P') {
                v->i = i;
                v->j = j;
                number += checkwino(map, v->mapo, v, nbr);
            }
            if (map[i][j] == 'O')
                number++;
        }
    }
    return (number);
}