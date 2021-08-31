/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** key
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

char **rightkey(char **map, int r, variable *v)
{
    int l = 0;

    for (; map[0][l] == '#' || map[0][l] == ' ' || map[0][l] == 'X'; l++);
    if (r == KEY_RIGHT) {
        if (v->j == l - 1 || v->j+1 == l -1 && map[v->i][v->j+1] == 'X')
            return (map);
        if (v->mapo[v->i][v->j] == 'O')
            map[v->i][v->j] = 'O';
        if (map[v->i][v->j+1] == 'X')
            return (moveboxright(map, r, v->i, v->j));
        if (map[v->i][v->j+1] == '#') {
            map[v->i][v->j] = 'P';
            return (map);
        }
        if (v->mapo[v->i][v->j] != 'O')
            map[v->i][v->j] = ' ';
        map[v->i][v->j+1] = 'P';
    }
    return (map);
}

char **leftkey(char **map, int r, variable *v)
{
    if (r == KEY_LEFT) {
        if (v->j == 0 || v->j-1 == 0 && map[v->i][v->j-1] == 'X')
            return (map);
        if (v->mapo[v->i][v->j] == 'O')
            map[v->i][v->j] = 'O';
        if (map[v->i][v->j-1] == 'X')
            return (moveboxleft(map, r, v->i, v->j));
        if (map[v->i][v->j-1] == '#') {
            map[v->i][v->j] = 'P';
            return (map);
        }
        if (v->mapo[v->i][v->j] != 'O')
            map[v->i][v->j] = ' ';
        map[v->i][v->j-1] = 'P';
    }
    return (map);
}

char **downkey(char **map, int r, variable *v, int nbr)
{
    if (r == KEY_DOWN) {
        if (v->i == nbr - 1 || v->i+1 == nbr - 1 && map[v->i+1][v->j] == 'X')
            return (map);
        if (v->mapo[v->i][v->j] == 'O')
            map[v->i][v->j] = 'O';
        if (map[v->i+1][v->j] == 'X')
            return (moveboxdown(map, r, v->i, v->j));
        if (map[v->i+1][v->j] == '#') {
            map[v->i][v->j] = 'P';
            return (map);
        }
        if (v->mapo[v->i][v->j] != 'O')
            map[v->i][v->j] = ' ';
        map[v->i+1][v->j] = 'P';
    }
    return (map);
}

char **upkey(char **map, int r, variable *v)
{
    if (r == KEY_UP) {
        if (v->i == 0 || v->i-1 == 0 && map[v->i-1][v->j] == 'X')
            return (map);
        if (v->mapo[v->i][v->j] == 'O')
            map[v->i][v->j] = 'O';
        if (map[v->i-1][v->j] == 'X')
            return (moveboxup(map, r, v->i, v->j));
        if (map[v->i-1][v->j] == '#') {
            map[v->i][v->j] = 'P';
            return (map);
        }
        if (v->mapo[v->i][v->j] != 'O')
            map[v->i][v->j] = ' ';
        map[v->i-1][v->j] = 'P';
    }
    return (map);
}

char **searchfind(char **map, int r, int nbr, variable *v)
{
    for (int i = 0; i != nbr; i++) {
        for (int j = 0; map[i][j] != '\n'; j++) {
            if (map[i][j] == 'P' ) {
                v->i = i;
                v->j = j;
                map = upkey(map, r, v);
                map = downkey(map, r, v, nbr);
                map = rightkey(map, r, v);
                map = leftkey(map, r, v);
                i = nbr-1;
                break;
            }
        }
    }
    return (map);
}